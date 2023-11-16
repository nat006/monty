#include "monty.h"

/* Global variable to hold the stack */
stack_t *stack = NULL;

/**
 * push - Pushes an element to the stack.
 * @line_number: The line number of the push opcode in the file.
 * @n: The value to be pushed to the stack.
 */
void push(unsigned int line_number, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack();
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (stack == NULL)
    {
        new_node->next = NULL;
        stack = new_node;
    }
    else
    {
        new_node->next = stack;
        stack->prev = new_node;
        stack = new_node;
    }
}
