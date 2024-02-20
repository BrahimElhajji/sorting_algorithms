#include "sort.h"

/**
 * swap - swaps
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array that we want to sort
 * @low: starting idx
 * @high: ending idx
 * @size: size of the array
 * Return: partition idx
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			++i;
		}
	}

	if (array[i] > array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - recursively sorts an array using quicksort
 * @array: array
 * @low: starting idx
 * @high: ending idx
 * @size: size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pi = lomuto_partition(array, low, high, size);

		if (pi > 0)
		{
			quick_sort_recursive(array, low, pi - 1, size);
		}

		if (pi + 1 < high)
		{
			quick_sort_recursive(array, pi + 1, high, size);
		}
	}
}

/**
 * quick_sort - sorts an array of ints
 * @array: array of ints
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

