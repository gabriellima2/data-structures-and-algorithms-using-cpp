#include <iostream>;
using namespace std;

// OBS: Come�a do final ao in�cio.

void heapify(int array[], int array_length, int initial_index)
{
    int largest_value_index = initial_index;
    int left_index = 2 * initial_index + 1;
    int right_index = 2 * initial_index + 2;

	// Se tiver item na esquerda e for maior que o maior valor: passar� a ser o maior valor
	if (left_index < array_length && array[left_index] > array[largest_value_index])
	{
		largest_value_index = left_index;
	}

	// Se tiver item na direita e for maior que o maior valor: passar� a ser o maior valor
	if (right_index < array_length && array[right_index] > array[largest_value_index])
	{
		largest_value_index = right_index;
	}

    if (largest_value_index != initial_index)
	{
        swap(array[initial_index], array[largest_value_index]);
        heapify(array, array_length, largest_value_index);
    }
}

void create_max_heap(int array[], int array_length)
{
	int const half_the_array_length = array_length / 2;
	for (int i = half_the_array_length - 1; i >= 0; i--)
	{
		heapify(array, array_length, i);
	}
}


void heap_sort(int array[], int array_length)
{
	// Cria uma Max-Heap. Um Heap Bin�rio com o maior valor na raiz
	create_max_heap(array, array_length);

	// Ordena a Heap criada. Passando os menores valores ao in�cio
	for (int i = array_length - 1; i > 0; i--)
	{
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}


int main()
{
	int array[] = { 32, 4, 99, 20, 17, 1, 55 };
	int array_length = sizeof(array) / sizeof(array[0]);
	heap_sort(array, array_length);
	return 0;
}
