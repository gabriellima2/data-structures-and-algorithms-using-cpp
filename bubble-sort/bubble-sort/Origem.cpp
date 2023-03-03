#include <iostream>;
using namespace std;

void bubble_sort(int array[], int array_length)
{
	int const total_indexes = array_length - 1;
	for (int count = 0; count < total_indexes; count++)
	{
		// Para o loop executar parcialmente, decrementando-o: 4 -> 3 -> 2 -> 1 -> 0
		int total_indexes_decremented = total_indexes - count;
		for (int current_index = 0; current_index < total_indexes_decremented; current_index++)
		{
			int next_index = current_index + 1;
			if (array[current_index] > array[next_index])
			{
				// swap(): Troca os valores de um indíce ao outro.
				// Como essa função está com o ponteiro, reflete no array do bloco da função main()
				swap(array[current_index], array[next_index]);
			}
		}
	}
}

int main()
{
	int array[] = { 2, 32, 1, 5 };
	int array_length = sizeof(array) / sizeof(array[0]);
	bubble_sort(array, array_length);
	cout << array;
	return 0;
}
