#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    dlistint_t *node_to_delete;
    unsigned int p;

    if (head == NULL || *head == NULL)
    {
        return (-1);
    }

    node_to_delete = *head;

    /* Traverse to the node at the given index */
    for (p = 0; p < index; p++)
    {
        if (node_to_delete == NULL)
        {
            return (-1);
        }
        node_to_delete = node_to_delete->next;
    }

    /* Check if node_to_delete is NULL, indicating that index is out of range */
    if (node_to_delete == NULL)
    {
        return (-1);
    }

    /* Handle the case when the node to delete is the head of the list */
    if (node_to_delete == *head)
    {
        *head = node_to_delete->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        /* Adjust the pointers of the previous and next nodes */
        if (node_to_delete->prev != NULL)
        {
            node_to_delete->prev->next = node_to_delete->next;
        }
        if (node_to_delete->next != NULL)
        {
            node_to_delete->next->prev = node_to_delete->prev;
        }
    }

    /* Free the memory of the node to delete */
    free(node_to_delete);

    return (1);
}
