#include "sort.h"
/**
 * insertion_sort_list - sorts a linkedList using the insertion sort algorithm
 *
 * @list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *sorted, *temp;

	sorted = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (*list != NULL)
	{
		current = *list;
		*list = (*list)->next;

		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			if (sorted)
				sorted->prev = current;
			sorted = current;
/*			print_list(*list);*/
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
			{
				temp = temp->next;
			}
			current->next = temp->next;
			if (temp->next)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
		}
		print_list(*list);
	}
	*list = sorted;
}
