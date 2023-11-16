#include "monty.h"

/**
 * rotl - Rotate the stack to the top
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *current = *head, *tmp, *aux;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    aux = (*head)->next;
    aux->prev = NULL;

    tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    *head = aux;
}
