#include "sort.h"
#include <stdio.h>

/**
 * swap - Intercambia dos elementos en un arreglo
 * @a: Primer elemento
 * @b: Segundo elemento
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Partición usando el esquema de Lomuto
 * @array: Arreglo de enteros
 * @low: indice de inicio de la sublista
 * @high: indice final (pivote)
 * @size: Tamaño total del arreglo (para imprimir)
 * Return: indice del pivote después de la partición
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Función recursiva para Quick Sort
 * @array: Arreglo de enteros
 * @low: indice de inicio
 * @high: indice de fin
 * @size: Tamaño del arreglo
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Función principal para Quick Sort
 * @array: Arreglo de enteros a ordenar
 * @size: Tamaño del arreglo
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
