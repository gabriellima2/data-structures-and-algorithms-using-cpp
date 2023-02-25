#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
	int total_length;
	void increment_first_element_index();
	void decrement_first_element_index();

public:
	T* data;
	int first_element_index;
	Queue(T value, int total_length);
	void enqueue(T value);
	T dequeue();
	void print();
	T dequeue_recover();
};

template <typename T>
Queue<T>::Queue(T data_param, int total_length_param)
{
	this->data = new T[total_length_param];
	this->data[0] = data_param;
	this->first_element_index = 0;
	this->total_length = total_length_param;
}

template <typename T>
void Queue<T>::increment_first_element_index()
{
	this->first_element_index = this->first_element_index + 1;
}

template <typename T>
void Queue<T>::decrement_first_element_index()
{
	this->first_element_index = this->first_element_index - 1;
}

template <typename T>
void Queue<T>::enqueue(T value)
{
	if (this->first_element_index < this->total_length) {
		this->increment_first_element_index();
		this->data[this->first_element_index] = value;
	}
}

template <typename T>
T Queue<T>::dequeue()
{
	if (this->first_element_index >= 0) {
		const T last_data = this->data[this->first_element_index];
		this->decrement_first_element_index();
		return last_data;
	}
}

template <typename T>
T Queue<T>::dequeue_recover()
{
	this->increment_first_element_index();
	return this->data[this->first_element_index];
}

int main()
{
	Queue<string> peoples("Jon Doe", 5);
	peoples.enqueue("Bruce Wayne");
	cout << peoples.dequeue() << endl;
	peoples.enqueue("Barry Allen");
	cout << peoples.dequeue() << endl;
	cout << peoples.dequeue() << endl;
	return 0;
}
