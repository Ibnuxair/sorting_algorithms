#include "sort.h"

/**
 * lomuto_partition - Partitions an array using Lomuto scheme.
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot element.
 */
size_t lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int temp;
	int j, i = low - 1;
	int swap_occurred;

	for (j = low; j <= high - 1; j++)
	{
		swap_occurred = 0;
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			swap_occurred = 1;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (swap_occurred)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Recursively sorts an array of integers using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void quicksort(int *array, size_t size, int low, int high)
{
	size_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);

		if (pivot != 0)
			quicksort(array, size, low, pivot - 1);
		quicksort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
