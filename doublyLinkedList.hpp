#include <stdexcept>
#include <iostream>

class KeyNotFoundException : public std::runtime_error 
{
public:
	explicit KeyNotFoundException(const std::string & err) : std::runtime_error(err) {}
};

template<typename Key, typename Value>
class SortedList
{
private:
	struct Node{
			Node(const Key &iKey, const Value &iValue)
			: nKey{iKey},nValue{iValue}, next{nullptr}, prev{nullptr}
			{}
			Key nKey;
			Value nValue;
			Node *next;
			Node *prev;
	};
	Node * head;

public:
	SortedList();

	SortedList(const SortedList & st);
	SortedList & operator=(const SortedList & st);
	~SortedList();

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	bool insert(const Key &k, const Value &v); 

	bool contains(const Key &k) const noexcept; 

	void remove(const Key &k);

	unsigned getIndex(const Key &k) const;

	Value & operator[] (const Key &k) ;

	const Value & operator [] (const Key & k) const; 

	const Key & largestLessThan(const Key & k) const;
	
    const Key & smallestGreaterThan(const Key & k) const;

	//Only applies when key-type and value-type have implemented operator==
	bool operator==(const SortedList & l) const noexcept;

	// preincrement every Value in the list.
	void operator++();

    //Print out the list
	void outputList();
};

//CONSTRUCTOR
template<typename Key, typename Value>
SortedList<Key,Value>::SortedList() : head(nullptr)
{

}

//COPY CONSTRUCTOR
template<typename Key, typename Value>
SortedList<Key,Value>::SortedList(const SortedList & st)
{
	Node *copyHead = st.head;
	//check if list is not null so there is something to copy
	if(copyHead != nullptr){		
		this->head = new Node(copyHead->nKey, copyHead->nValue);
		copyHead = copyHead->next;
		while(copyHead != nullptr){
			this->insert(copyHead->nKey, copyHead->nValue);
			copyHead = copyHead->next;
		}
	}
}

//ASSIGNMENT OPERATOR
template<typename Key, typename Value>
SortedList<Key,Value> & SortedList<Key,Value>::operator=(const SortedList & st)
{
	//self assignment
	if( this == &st )
	{
		return *this;
	}
	//not self assigned
	//Clean up just in case
	while (head != nullptr){
		Node * temp = head;
		head = head->next;
		delete temp;
	}
	//copy constructor
	Node *copyHead = st.head;
	//check if list is not null so there is something to copy
	if(copyHead != nullptr){		
		this->head = new Node(copyHead->nKey, copyHead->nValue);
		copyHead = copyHead->next;
		while(copyHead != nullptr){
			this->insert(copyHead->nKey, copyHead->nValue);
			copyHead = copyHead->next;
		}
	}

	return *this;

}

//DESTRUCTOR
template<typename Key, typename Value>
SortedList<Key,Value>::~SortedList()
{
	//Delete Nodes
	while (head != nullptr){
		Node * temp = head;
		head = head->next;
		delete temp;
	}
}

//Return size of list
template<typename Key, typename Value>
size_t SortedList<Key,Value>::size() const noexcept
{
	size_t count = 0;
	Node *current = head;
	while (current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

//Check is list is empty
template<typename Key, typename Value>
bool SortedList<Key,Value>::isEmpty() const noexcept
{
	return head == nullptr;
}

//Insert
//If the key already exists, return false.
// else, inserting key/value pair, return true
template<typename Key, typename Value>
bool SortedList<Key,Value>::insert(const Key &k, const Value &v)
{
	Node *newNode = new Node(k,v);
	//std::cout<<"New node created: "<<newNode->nKey<<newNode->nValue<<std::endl;
	Node *current = head; //The current Node
	Node *previous = nullptr; //The previous Node

	//Find correct position to insert
	while (current != nullptr && current->nKey < k){
		previous = current;
		current = current->next;
	}
	//Check if Key already exists
	if (current != nullptr && current->nKey == k){
		delete newNode;
		return false;
	}
	//Insert Node into queue
	//k is the smallest index, we add to beginning
	if (previous == nullptr){
		newNode->next = head;
		if (head != nullptr){ //check if list was not empty
			head->prev = newNode;
		}
		head = newNode;
	}
	else{
		//Inserting between two other nodes
		newNode->next = current;
		newNode->prev = previous;
		previous->next = newNode;
		if (current != nullptr){
			current ->prev = newNode;
		}
	}
	return true;
}

//Check if list contains specified Key
template<typename Key, typename Value>
bool SortedList<Key,Value>::contains(const Key &k) const noexcept
{
	Node *current = head;
	//Search queue for k
	while (current != nullptr){
		if (current->nKey == k){
			return true;
		}
		current = current->next;
	}
	return false;
}

//Remove Key-Value pair from list
template<typename Key, typename Value>
void SortedList<Key,Value>::remove(const Key &k) 
{
	Node *current = head;
	//Find the node with the key
	while (current != nullptr && current->nKey < k){ //stop before exceeding value of k so we land in the right place
		current = current->next;
	}
	//Check if key K exists
	if (current != nullptr && current->nKey == k){
		//current will be deleted so we must redirect pointers
		if (current->prev != nullptr){
			//if there is a previous node before, change its next pointer to the node after current
			current->prev->next = current->next;
		}
		else{
			//no previous, then the head will be the node after current
			head = current->next;
		}
		if (current->next != nullptr){
			//If there is a node after current, update its prev pointer
			current->next->prev = current-> prev;
		}
		//abolish the node and send to the shadow realm
		delete current;
	}
}

// If key exists in the list, return the number of keys that are less than specified key
// If key does not exist in the list, throw a KeyNotFoundException.
template<typename Key, typename Value>
unsigned SortedList<Key,Value>::getIndex(const Key &k) const
{
	//Does list contain k?
	if (this->contains(k) == false){
		throw KeyNotFoundException{"Key not found in list"};
	}
	//Count keys before k
	unsigned count = 0;
	Node *current = head;
	while (current != nullptr && current->nKey < k){ //stop before exceeding value of k so we land in the right place
		count++;
		current = current->next;
	}
	return count;
}

//Does key exist, return modifiable version
template<typename Key, typename Value>
Value & SortedList<Key,Value>::operator[] (const Key &k) 
{
	Node *current = head;
	while(current != nullptr){
		if(current->nKey == k){
			return current->nValue; //modifiable type of value
		}
		current = current ->next;
	}
	throw KeyNotFoundException{"Key not found in list"};  // STUB;  fix then remove this comment

}

//Does key exist, return non-modifiable version
template<typename Key, typename Value>
const Value & SortedList<Key,Value>::operator[] (const Key &k) const 
{
	Node *current = head;
	while(current != nullptr){
		if(current->nKey == k){
			return current->nValue; //modifiable type of value
		}
		current = current ->next;
	}
	throw KeyNotFoundException{"Key not found in list"};  // STUB;  fix then remove this comment

}

//Given the specified key, return the largest key that is less than the specified key
// if it does not exist, throw KeyNotFoundException
template<typename Key, typename Value>
const Key & SortedList<Key,Value>::largestLessThan(const Key & k) const
{
	//if key k is at the start of the list, there is no other key less than it
	Node *current = head;
	//check if k is less than the first key
	if(k <= current->nKey){
		throw KeyNotFoundException{"Key not found in list"};
	}
	//Navigate through list
	const Key *largestKey = nullptr;
	while (current != nullptr && current->nKey < k){ //stop before exceeding value of k so we land in the right place
		largestKey = &current->nKey;
		current = current->next;
	}
	return *largestKey;
}

//Given the specified key, return the smallest key that is greater than the specified key
// if it does not exist, throw KeyNotFoundException
template<typename Key, typename Value>
const Key & SortedList<Key,Value>::smallestGreaterThan(const Key & k) const
{
	//Find the last key, if k exceeds the last key, there is no smallest value greater than
	Node *current = head;
	while (current->next != nullptr){
		current = current->next;
	}
	if(current->nKey <= k){
		throw KeyNotFoundException{"Key not found in list"};
	}
	//reset
	current = head;
	while(current != nullptr){
		if (current->nKey > k){
			return current->nKey;
		}
		current = current->next;
	}
	
	//If something got past our error checking
	throw KeyNotFoundException{"Key not found in list"};

}

//== operator
//check if list size, and Key-Value pairs are the same or not
template <typename Key, typename Value>
bool SortedList<Key,Value>::operator==(const SortedList & l) const noexcept
{
	//l is another sorted list
	if (this->size() != l.size()){
		return false;
	}
	//This == Other
	Node * currentThis = this->head;
	Node *currentOther = l.head;
	while(currentThis != nullptr && currentOther != nullptr){
		//compare keys and values
		if (currentThis->nKey != currentOther->nKey || currentThis->nValue != currentOther->nValue){
			return false;
		}
		currentThis = currentThis->next;
		currentOther = currentOther->next;
	}
	return true;
}

//++ pre-increment
template <typename Key, typename Value>
void SortedList<Key,Value>::operator++()
{
	Node *current = head;
	while (current != nullptr){
		++(current->nValue);
		current = current->next;
	}
}

//For visualization, print out the list
template <typename Key, typename Value>
void SortedList<Key,Value>::outputList()
{
	Node *current = head;

	while (current != nullptr){
		std::cout<<""<<current->nKey<<": "<<current->nValue<<std::endl;
		current = current->next;
	}
}