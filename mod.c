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
 * mod - Modulus function
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void mod(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    int length = get_stack_length(head);
    int remainder;

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    remainder = current->next->n % current->n;
    current->next->n = remainder;
    *head = current->next;
    free(current);
}
