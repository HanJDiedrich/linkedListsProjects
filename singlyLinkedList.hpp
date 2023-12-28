#include <iostream>
#include <string>
#include <stdexcept>

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

