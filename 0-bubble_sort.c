#include "sort.h"

/**
 * swap - swap function
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - bubble sort algorithm
 * @array: pointer to an array of ints
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (j = 1; j < size; j++)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
			}
			else
				continue;
		}

	}

}
