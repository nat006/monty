#include "monty.h"


/**
 * get_stack_length - Get the length of the stack
 * @head: Stack head
 * Return: Length of the stack
 */
int get_stack_length(stack_t **head)
{
    stack_t *current = *head;
    int length = 0;

    while (current)
    {
        current = current->next;
        length++;
    }

    return length;
}

/**
 * f_mul - Multiplication function
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_mul(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    int length = get_stack_length(head);
    int product;

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    product = current->next->n * current->n;
    current->next->n = product;
    *head = current->next;
    free(current);
}
