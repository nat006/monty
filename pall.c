#include "monty.h"
/**
 * pall - Prints all the values on the stack.
 * @line_number: The line number of the pall opcode in the file.
 */
void pall(unsigned int line_number)
{
    stack_t *temp = stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
