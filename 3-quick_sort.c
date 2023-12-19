#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @size: Size of the array
 * @low: Lowest index of the partition
 * @high: Highest index of the partition
 *
 * Return: Index of the partition element
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_recursive - Recursive function for Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @low: Lowest index of the partition
 * @high: Highest index of the partition
 */
void quicksort_recursive(int *array, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, size, low, high);

		quicksort_recursive(array, size, low, partition - 1);
		quicksort_recursive(array, size, partition + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
