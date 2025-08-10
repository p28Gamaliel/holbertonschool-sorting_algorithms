#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - ordena un arreglo de enteros de forma ascendente
 * @array: arreglo de enteros a ordenas
 * @size: tamano del arreglo
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size -  1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);

				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}
