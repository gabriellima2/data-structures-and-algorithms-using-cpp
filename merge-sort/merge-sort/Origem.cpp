#include <iostream>;
using namespace std;

void merge(int array[], int begin_index, int mid_index, int end_index)
{
    // Comprimento dos sub-arrays
    int const left_array_length = mid_index - begin_index + 1;
    int const right_array_length = end_index - mid_index;

    // Criação dos sub-arrays
    int* left_array = new int[left_array_length];
    int* right_array = new int[right_array_length];

    // Preenchendo os sub-arrays com os dados do array
    for (int current_index = 0; current_index < left_array_length; current_index++)
    {
        left_array[current_index] = array[begin_index + current_index];
    }
    for (int current_index = 0; current_index < right_array_length; current_index++)
    {
        right_array[current_index] = array[mid_index + 1 + current_index];
    }

    int current_index_left_array = 0;
    int current_index_right_array = 0;
    int current_index_merged_array = begin_index;

    // Merge dos sub-arrays no array principal, já ordenando-o. Os menores no início e os maiores no final.
    while (
        current_index_left_array < left_array_length &&
        current_index_right_array < right_array_length
      )
    {
        if (left_array[current_index_left_array] <= right_array[current_index_right_array])
        {
            array[current_index_merged_array] = left_array[current_index_left_array];
            current_index_left_array++;
        }
        else {
            array[current_index_merged_array] = right_array[current_index_right_array];
            current_index_right_array++;
        }
        current_index_merged_array++;
    }

    // Merge dos elementos restantes do sub-array esquerdo.
    while (current_index_left_array < left_array_length)
    {
        array[current_index_merged_array] = left_array[current_index_left_array];
        current_index_left_array++;
        current_index_merged_array++;
    }

    // Merge dos elementos restantes do sub-array direito.
    while (current_index_right_array < right_array_length)
    {
        array[current_index_merged_array] = right_array[current_index_right_array];
        current_index_right_array++;
        current_index_merged_array++;
    }

    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int array[], int begin_index, int end_index)
{
	if (begin_index >= end_index) return;

    // "Corta" o array até não ser mais possível, depois começa a ordenar.
	int mid_index = begin_index + (end_index - begin_index) / 2;
	merge_sort(array, begin_index, mid_index);
	merge_sort(array, mid_index + 1, end_index);
	merge(array, begin_index, mid_index, end_index);
}

int main()
{
	int array[] = { 3, 4, 1, 2 };
	int array_length = sizeof(array) / sizeof(array[0]);
	merge_sort(array, 0, array_length - 1);
	return 0;
}
