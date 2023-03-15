#include <iostream>;
using namespace std;

int binary_search(int array[], int initial_index, int last_index, int value_to_search)
{
	if (initial_index > last_index) return -1;

	int const middle = (initial_index + last_index) / 2;
	if (value_to_search == array[middle]) return middle;
	
	if (value_to_search > array[middle]) {
		return binary_search(array, middle + 1, last_index, value_to_search);
	}
	else if (value_to_search < array[middle]) {
		return binary_search(array, initial_index, middle - 1, value_to_search);
	}
	return -1;
}

int main()
{
	int sorted_array[] = { 1, 5, 9, 55, 89, 120, 188, 200 };
	int const array_length = sizeof(sorted_array) / sizeof(sorted_array[0]);
	int const value_to_search = 55;
	cout << binary_search(sorted_array, 0, array_length, value_to_search);
	return 0;
}
