#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number in the file.
 *
 * Description: The pint function prints the value at the top of the stack,
 * followed by a new line. If the stack is empty, it prints an error message
 * and exits with the status EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
