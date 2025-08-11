#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Ordena un arreglo de enteros en orden ascendente
 *                  usando el algoritmo de Selection Sort
 * @array: El arreglo de enteros a ordenar
 * @size: El tamaño del arreglo
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (!array || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			min_idx = j;
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
