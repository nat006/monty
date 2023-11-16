#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer
 * @str: String to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++)
    {
        if (str[i] > '9' || str[i] < '0')
            return (0);
    }
    return (1);
}

/**
 * push - Add node to the stack
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void push(stack_t **head, unsigned int counter)
{
    int n;

    if (!bus.arg || !is_integer(bus.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
