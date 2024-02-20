#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: double pointer to the list
 * Return: always 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	new_node = (*list)->next;
	while (new_node != NULL)
	{
		temp = new_node->prev;
		while ((temp) && (temp->n > new_node->n))
		{
			if (new_node->next != NULL)
				new_node->next->prev = temp;
			temp->next = new_node->next;
			new_node->prev = temp->prev;
			new_node->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = new_node;
			temp->prev = new_node;
			if (temp == *list)
				*list = new_node;

			print_list(*list);

			if (new_node->prev != NULL)
				temp = new_node->prev;
			else
				break;
		}
		new_node = new_node->next;
	}
}
