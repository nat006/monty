#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 * @n: integer to be pushed
 *
 * Return: void
 */
void push(StackNode **stack, unsigned int line_number, int n)
{
    StackNode *new_node = malloc(sizeof(StackNode));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = *stack;
    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void pall(StackNode **stack, unsigned int line_number)
{
    StackNode *temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->prev;
    }
}
