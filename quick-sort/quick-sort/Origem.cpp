#include <iostream>;
using namespace std;

/*
	Existem implementa��es que escolhem o piv� de maneira diferente.

	- Primeiro elemento como piv�;
	- �ltimo elemento como piv�; (Implementa��o desse!)
	- Elemento aleat�rio como piv�;
	- Elemento mediano como piv�.
*/

int partition(int array[], int lowest_index, int highest_index)
{
	int pivot = array[highest_index];
	int sorted_element_count = lowest_index - 1;
	int second_to_last_index = highest_index - 1;

	// Itera at� o pen�ltimo
	for (int current_index = lowest_index; current_index <= second_to_last_index; current_index++)
	{
		if (array[current_index] < pivot)
		{
			// Para passar o menor valor � esquerda. Se for o mesmo valor nada acontece.
			sorted_element_count++;
			swap(array[sorted_element_count], array[current_index]);
		}
	}
	// Para passar o maior valor � direita. Se for o mesmo valor nada acontece.
	swap(array[sorted_element_count + 1], array[highest_index]);
	return sorted_element_count + 1; // Para particionar o array.
}

void quick_sort(int array[], int lowest_index, int highest_index)
{
	if (lowest_index > highest_index) return;
	
	int partitioned_index = partition(array, lowest_index, highest_index);
	quick_sort(array, lowest_index, partitioned_index - 1); // Ignorando os �ltimos
	quick_sort(array, partitioned_index + 1, highest_index); // Ignorando os primeiros
}

int main()
{
	int array[] = { 4, 2, 8, 9, 3, 12, 3 };
	int array_length = sizeof(array) / sizeof(array[0]);
	quick_sort(array, 0, array_length - 1);
	return 0;
}