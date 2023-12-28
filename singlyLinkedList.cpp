#include <iostream>
#include <string>
#include <stdexcept>
#include "singlyLinkedList.hpp"

/*.hpp file
class QueueEmptyException : public std::runtime_error 
{
public:
	explicit QueueEmptyException(const std::string & err) : std::runtime_error(err) {}
};

class QueueOfStrings
{
private:
//new type (node) and such
//Declaration NODE
	struct Node{
		Node(std::string elem)
		: value{elem},next{nullptr}
		{}
		std::string value;
		Node *next;
	};
	Node * head;

public:
	QueueOfStrings();

	QueueOfStrings(const QueueOfStrings & st);

	QueueOfStrings & operator=(const QueueOfStrings & st);

	~QueueOfStrings();

	size_t size() const noexcept;

	bool isEmpty() const noexcept;

	void enqueue(const std::string & elem);

	std::string & front();

	const std::string & front() const;

	void dequeue();

	void printList();
};
*/

//Constructor
QueueOfStrings::QueueOfStrings(): head(nullptr) //:variable{0}
{
	//initilaize member variables (if created)
}

//Copy Constructor
QueueOfStrings::QueueOfStrings(const QueueOfStrings & st)
{
	//initialize instance based on a different one
	Node * copyhead = st.head;
	this->head = new Node(copyhead->value);
	copyhead = copyhead->next;

	while(copyhead != nullptr){
		this->enqueue(copyhead->value);
		copyhead = copyhead->next;
	}
	//QueueOfStrings Q2 = Q1; or QueueofStrings Q2(Q1)
}

//Assignment Operator
QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	if (this == &st){
		return *this;
	}

	Node * copyhead = st.head;
	this->head = new Node(copyhead->value);
	copyhead = copyhead->next;
	
	while(copyhead != nullptr){
		this->enqueue(copyhead->value);
		copyhead = copyhead->next;
	}

	return *this;
}

//Destructor
QueueOfStrings::~QueueOfStrings() 
{
	//delete all nodes in our list
	while(head != nullptr){
		Node * temp = head;
		head = head->next; //Set the following node to the head
		delete temp;
	}
}

//Return the size of the list
size_t QueueOfStrings::size() const noexcept
{
	size_t count = 0;
	Node * temp = head;
	while (temp != nullptr){
		count++;
		//std::cout << temp->value;
		temp = temp->next;
	}
	return count; //done
}

//Check if the list is empty
bool QueueOfStrings::isEmpty() const noexcept
{
	return head == nullptr; //DONE
}

//Add an element(string) to the end of the line(linked list)
void QueueOfStrings::enqueue(const std::string & elem)
{
	if(head == nullptr){
		Node *temp{head};
		head = new Node(elem);
		head ->next = temp;
	}
	else{
		Node * temp{head};
		while(temp ->next != nullptr){
			temp = temp ->next;
		}
		temp ->next = new Node(elem);
	}
}	

//Get the first element in the list (modifiable)
std::string & QueueOfStrings::front()
{
	if (isEmpty()){
		throw QueueEmptyException{"Queue is Empty"};
	}
	return head->value;
}

//Get the first element in the list (non-modifiable)
const std::string & QueueOfStrings::front() const
{
	if (isEmpty()){
		throw QueueEmptyException{"Queue is Empty"};
	}
	return head->value;
}

//Remove the first element
void QueueOfStrings::dequeue()
{
	if (isEmpty()){
		throw QueueEmptyException{"Queue is Empty"};
	}
	Node * temp = head;
	head = head->next; //Set the following node to the head
	delete temp;
}

//Print out the list
void QueueOfStrings::printList(){
	Node * temp = head;
	while (temp != nullptr){
		std::cout << temp->value<<" ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

int main(){
    QueueOfStrings myList;
    myList.enqueue("Hello");
    myList.enqueue("Hi");
    myList.printList();

    return 0;
}