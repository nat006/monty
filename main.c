#include "monty.h"
int main(void)
{
    stack_t *head = NULL;
    unsigned int counter = 1;
    
    /* Example usage */
    printf("Creating initial stack...\n");
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    
    printf("Printing stack before rotation:\n");
    print_stack(head);
    
    printf("Rotating stack to the top...\n");
    f_rotl(&head, counter);
    
    printf("Printing stack after rotation:\n");
    print_stack(head);
    
    printf("Freeing stack...\n");
    free_stack(head);
    
    return 0;
}
