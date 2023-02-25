#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
	int max_length;
	void decrement_length();
	void increment_length();

public:
	T* data;
	int length;
	Stack(T value, int max_length);
	void add(T value);
	bool isEmpty();
	T peek();
};

template <typename T>
Stack<T>::Stack(T value, int max_length)
{
	this->data = new T[max_length];
	this->data[0] = value;
	this->length = 1;
	this->max_length = max_length;
}

template <typename T>
void Stack<T>::decrement_length()
{
	this->length = this->length - 1;
}

template <typename T>
void Stack<T>::increment_length()
{
	this->length = this->length + 1;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return this->length == 0;
}

template <typename T>
void Stack<T>::add(T value)
{
	if (this->length < this->max_length) {
		this->data[this->length] = value;
		this->increment_length();
	}
}

template <typename T>
T Stack<T>::peek()
{
	if (!this->isEmpty()) {
		const int index_value_on_top = this->length - 1;
		const T value_on_top = this->data[index_value_on_top];
		this->decrement_length();
		return value_on_top;
	}
}

int main()
{
	Stack<string> books_to_ready("Clean Code", 3);
	books_to_ready.add("SOLID Principles");
	books_to_ready.add("Hello World with C");
	cout << books_to_ready.peek() << endl;
	cout << books_to_ready.peek() << endl;
	cout << books_to_ready.peek() << endl;
	return 0;
}