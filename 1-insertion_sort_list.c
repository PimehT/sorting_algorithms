#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort algorithm
 *
 * @list: Pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *before = temp->prev;
			listint_t *after = temp->next;

			before->next = after;

			if (after != NULL)
				after->prev = before;

			temp->prev = before->prev;
			temp->next = before;

			if (before->prev != NULL)
				before->prev->next = temp;

			before->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
