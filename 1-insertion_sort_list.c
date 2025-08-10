#include "sort.h"

/**
 * swap_nodes - Intercambia dos nodos adyacentes en una lista doble
 * @list: Doble puntero al inicio de la lista
 * @left: Nodo izquierdo
 * @right: Nodo derecho
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right || !list)
		return;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;
}

/**
 * insertion_sort_list - Ordena una lista doblemente enlazada
 *                       de enteros usando Insertion Sort
 * @list: Puntero al inicio de la lista
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
	current = current->next;
	}
}
