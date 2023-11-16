#include "monty.h"

/**
 * get_stack_length - Get the length of the stack
 * @head: Stack head
 * Return: Length of the stack
 */
int get_stack_length(stack_t **head)
{
    stack_t *aux = *head;
    int nodes = 0;

    while (aux != NULL)
    {
        aux = aux->next;
        nodes++;
    }

    return nodes;
}

/**
 * sub - Subtraction function
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void sub(stack_t **head, unsigned int counter)
{
    stack_t *aux = *head;
    int nodes = get_stack_length(head);
    int sub;

    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    sub = aux->next->n - aux->n;
    aux->next->n = sub;
    *head = aux->next;
    free(aux);
}
