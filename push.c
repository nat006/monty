#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number in the file.
 * @argument: The argument to be pushed onto the stack.
 *
 * Description: The push function pushes an element to the stack.
 * If the argument is not an integer or if there is no argument given,
 * it prints an error message and exits with the status EXIT_FAILURE.
 * It then converts the argument to an integer using the atoi function
 * and adds the integer value to the stack.
 */
void push(stack_t **stack, unsigned int line_number, char *argument)
{
int value;

if (argument == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

if (!is_integer(argument))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(argument);
add_node(stack, value);
}

/**
 * is_integer - Checks if a string is an integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 *
 * Description: The is_integer function checks if a string is an integer.
 * It returns 1 if the string consists of only digits, and 0 otherwise.
 */
int is_integer(char *str)
{
int i = 0;

if (str == NULL)
return (0);

if (str[i] == '-')
i++;

for (; str[i] != '\0'; i++)
{
if (!isdigit(str[i]))
return (0);
}

return (1);
}
