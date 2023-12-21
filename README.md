---doublyLinkedList.cpp---
-------------------------------------------------------------------------------------------------------------------------
Implemented a doubly linked list with pointers to previous and next nodes.
The list is sorted in ascending order.
Uses templated types for Key, Value pair to accomodate different data types.

Functions:
SortedList(); -- Constructor, initialize the head of the list

SortedList(const SortedList & st); -- Copy constructor, creates an identical list of st

SortedList & operator=(const SortedList & st); -- Assignment Operator, assigns a sortedList to sortedList st

~SortedList(); -- Destructor for memory management

size_t size() const noexcept; -- Returns the number of elements in a list

bool isEmpty() const noexcept; -- Checks if a list contains no elements

bool insert(const Key &k, const Value &v); -- Inserts a Key, Value pair into the list sorted in position based on Key

bool contains(const Key &k) const noexcept; -- Determines if a list contains specified Key

void remove(const Key &k); -- Removes the Key, Value pair associated with Key and reassigns pointers

unsigned getIndex(const Key &k) const; -- Returns the number of Keys that are less than specified Key. Throws exception if Key doesn't exist

Value & operator[] (const Key &k); -- [] operator, returns modifiable type of Value, if Key doesn't exist throws exception

const Value & operator [] (const Key & k) const; -- [] operator, returns unmodifiable type of Value, if Key doesn't exist throws exception

const Key & largestLessThan(const Key & k) const; -- Returns the largest key that is less than specified key, if there is none throws exception

const Key & smallestGreaterThan(const Key & k) const; -- Returns the smallest key that is greater than specified key, if there is none throws exception

bool operator==(const SortedList & l) const noexcept; -- Checks if a sortedList is identical to sortedList l. Only applies for lists where Key-type and Value-type have implemented operator == 

void operator++(); -- Pre-increments every Value in the list

void outputList(); -- Prints out the list in terminal

-------------------------------------------------------------------------------------------------------------------------

---singlyLinkedList.cpp---
-------------------------------------------------------------------------------------------------------------------------
Implementing a singly linked list of std::string types with pointer to next element

Functions:
QueueOfStrings(); -- Constructor, initialize the head of list

QueueOfStrings(const QueueOfStrings & st); -- Copy constructor, creates an identical list of st

QueueOfStrings & operator=(const QueueOfStrings & st); -- Assignment Operator, assigns a sortedList to sortedList st

~QueueOfStrings(); -- Destructor for memory management

size_t size() const noexcept; -- Returns the number of elements in a list

bool isEmpty() const noexcept; -- Checks if a list contains no elements

void enqueue(const std::string & elem); -- Adds an element to the end of the list, reassigned pointer

std::string & front(); -- Returns a modifiable version of the first element in the list

const std::string & front() const; -- Returns a unmodifiable version of the first element in the list

void dequeue(); -- Removes first element in the list, reassigned pointer

void printList(); -- Prints out the list in terminal

-------------------------------------------------------------------------------------------------------------------------