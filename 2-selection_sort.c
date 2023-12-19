#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending order
 * using selection sort
 *
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}

		temp = array[i];
		array[i] = array[k];
		array[k] = temp;
		print_array(array, size);
	}
}
