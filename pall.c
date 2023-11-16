#include "monty.h"

/**
 * print_stack - Prints the stack
 * @head: Stack head
 * Return: No return
 */
void print_stack(stack_t **head)
{
    stack_t *h = *head;

    if (h == NULL)
        return;

    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

/**
 * pall - Wrapper function for printing the stack
 * @head: Stack head
 * @counter: Not used
 * Return: No return
 */
void pall(stack_t **head, unsigned int counter)
{
    (void)counter;
    print_stack(head);
}
