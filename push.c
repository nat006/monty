#include "monty.h"
#include <ctype.h>

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @value: Value to push
 *
 * Return: 1 on success, 0 on failure
 */
int push(stack_t *stack, unsigned int line_number, int value)
{
    if (stack->size >= STACK_SIZE)
    {
        fprintf(stderr, "L%u: Stack overflow\n", line_number);
        return (0);
    }

    stack->stack[stack->size++] = value;
    return (1);
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 */
void pall(stack_t *stack)
{
    size_t i;

    for (i = stack->size; i > 0; i--)
        printf("%d\n", stack->stack[i - 1]);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vectors
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL, *opcode, *value_str;
    size_t line_len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    int value;
    stack_t stack = {NULL, 0};

    if (argc != 2)
    {
        fprintf(stderr, "Usage: push_pop <file>\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while ((read = getline(&line, &line_len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t\r");
        if (!opcode)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            value_str = strtok(NULL, " \n\t\r");
            if (!value_str || !isdigit(*value_str) && *value_str != '-')
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                return (EXIT_FAILURE);
            }
            value = atoi(value_str);
            if (!push(&stack, line_number, value))
            {
                free(line);
                fclose(file);
                return (EXIT_FAILURE);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
    }

    free(line);
    fclose(file);
    return (EXIT_SUCCESS);
}
