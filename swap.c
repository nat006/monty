#include "monty.h"

/**
 * get_stack_length - Get the length of the stack
 * @head: Stack head
 * Return: Length of the stack
 */
int get_stack_length(stack_t **head)
{
    stack_t *h = *head;
    int len = 0;

    while (h)
    {
        h = h->next;
        len++;
    }

    return len;
}

/**
 * swap - Swaps the top two elements of the stack
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void swap(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;
    int len = get_stack_length(head);
    int aux;

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = h->n;
    h->n = h->next->n;
    h->next->n = aux;
}
