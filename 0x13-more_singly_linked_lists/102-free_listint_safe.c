#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_elements = 0;
	int difference;
	listint_t *temporary;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		difference = *head - (*head)->next;
		if (difference > 0)
		{
			temporary = (*head)->next;
			free(*head);
			*head = temporary;
			num_elements++;
		}
		else
		{
			free(*head);
			*head = NULL;
			num_elements++;
			break;
		}
	}

	*head = NULL;

	return (num_elements);
}
