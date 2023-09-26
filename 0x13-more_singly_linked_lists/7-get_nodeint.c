#include "lists.h"

/**
 * find_node_at_index - Retrieves the node at specified index in a linked list
 * @head: Pointer to the first node in the linked list
 * @index: Index of the node to retrieve
 *
 * Return: Pointer to the desired node or NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *current = head;

	while (current && count < index)
	{
		current = current->next;
		count++;
	}

	return (current ? current : NULL);
}
