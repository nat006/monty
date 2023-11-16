#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int is_integer(char *str);
void push(stack_t **head, unsigned int counter);
void print_stack(stack_t **head);
void pall(stack_t **head, unsigned int counter);
int get_stack_length(stack_t **head);
void swap(stack_t **head, unsigned int counter);
int get_stack_length(stack_t **head);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void div(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter);


#endif /* __MONTY_H__ */
