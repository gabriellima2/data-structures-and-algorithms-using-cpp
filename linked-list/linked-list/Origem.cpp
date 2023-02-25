#include <iostream>

using namespace std;

// Para valores ou tipos dinâmicos devemos usar ponteiros.

struct Node
{
	string value;
	struct Node* next;
};

class LinkedList
{
public:
	int length;
	LinkedList();
	Node* getByIndex(int index);
	Node* getByValue(string value);
	void insert(string value);
	void insertNodeAtPosition(int index, string value);
	void pop();
	void shift();
	void removeByNode(Node* node);
	void print();

private:
	Node* head;
	Node* tail;
};

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

void LinkedList::insert(string value)
{
	Node* node = new Node();
	node->value = value;
	node->next = nullptr;

	if (this->length == 0)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		this->tail->next = node;
		this->tail = node;
	}
	this->length = this->length + 1;
}

Node* LinkedList::getByIndex(int index)
{
	if (this->length == 0 || index > this->length) return NULL;
	
	Node* current_node = this->head;
	int count = 0;
	while (count < index && current_node != nullptr)
	{
		current_node = current_node->next;
		count = count + 1;
	}
	return current_node;
}

Node* LinkedList::getByValue(string value)
{
	if (this->length == 0) return NULL;

	Node* current_node = this->head;
	if (current_node->value == value) return current_node;

	while (current_node->next)
	{
		current_node = current_node->next;
		if (current_node->value == value) break;
		if (current_node->next == nullptr) {
			delete current_node;
			current_node = nullptr;
			break;
		}
	}
	return current_node;
}

void LinkedList::pop()
{
	if (this->length == 0) return;
	if (this->length == 1)
	{
		this->length = 0;
		// Antes de reatribuir um valor ao ponteiro, devemos deletá-lo manualmente.
		delete this->head;
		this->head = nullptr;
		return;
	}
	
	Node* current_node = this->head;
	int count = 0;
	while (current_node->next)
	{
		// Se o ponteiro do próximo nó for null, então estamos no penúltimo
		if (current_node->next->next == nullptr)
		{
			delete current_node->next;
			current_node->next = nullptr;
			this->tail = current_node;
			this->length = this->length - 1;
			break;
		}

		current_node = current_node->next;
		count = count + 1;
	}
}

void LinkedList::shift()
{
	if (this->length == 0) return;
	
	Node* nodes = this->head->next;
	delete this->head;
	this->head = nodes;
	this->length = this->length - 1;
}

void LinkedList::removeByNode(Node* node)
{
	if (node == nullptr) return;
	if (this->head == node) {
		this->shift();
		return;
	}

	Node* current_node = this->head;
	while (current_node->next != node && current_node->next != nullptr)
	{
		current_node = current_node->next;
	}
	current_node->next = node->next;
	this->length = this->length - 1;
}

void LinkedList::insertNodeAtPosition(int index, string value)
{
	if (index > this->length - 1 || index < 0) return;

	Node* previous_node = new Node();
	Node* current_node = this->head;
	Node* node = new Node();

	if (index == 0)
	{
		node->value = value;
		node->next = this->head->next;
		this->head = node;
	}

	for (int count = 1; count <= index; count++)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}

	node->value = value;
	previous_node->next = node;
	node->next = current_node->next;
}

void LinkedList::print()
{
	Node* current_node = this->head;
	while (current_node != nullptr)
	{
		cout << current_node->value << endl;
		current_node = current_node->next;
	}
}

int main()
{
	LinkedList users = LinkedList();
	users.insert("user1");
	users.insert("user2");
	users.insert("user3");
	users.insert("user4");
	users.insertNodeAtPosition(0, "user1_insert_after");
	users.print();
	return 0;
}