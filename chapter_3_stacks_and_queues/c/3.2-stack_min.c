#include "stack.h"

typedef struct stack_with_min
{
    node *values;
    node *mins;
} swm;

swm *create_swm()
{
    swm *stack = malloc(sizeof(swm));
    stack->values = NULL;
    stack->mins = NULL;
    return stack;
}

int min_swm(swm *stack)
{
    return peek(stack->mins);
}

void push_swm(swm *stack, int value)
{
    if (value < min_swm(stack))
        push(&stack->mins, value);
    push(&stack->values, value);
}

int pop_swm(swm *stack)
{
    int value;

    value = pop(&stack->values);
    if (value == min_swm(stack))
        pop(&stack->mins);
    return value;
}

int main()
{
    int i;
    int arr[] = {5, 1, -3, 9, -4};
    int size = sizeof(arr) / sizeof(int);
    swm *stack = create_swm();

    for (i = 0; i < size; i++)
        push_swm(stack, arr[i]);
    print_stack(stack->values);
    /* -4 9 -3 1 5 */
    print_stack(stack->mins);
    /* -4 -3 1 5 */
    printf("%i\n", min_swm(stack)); // -4
    printf("%i\n", pop_swm(stack)); // -4
    print_stack(stack->values);
    /* 9 -3 1 5 */
    print_stack(stack->mins);
    /* -3 1 5 */
    printf("%i\n", min_swm(stack)); // -3
    printf("%i\n", pop_swm(stack)); // 9
    print_stack(stack->values);
    /* -3 1 5 */
    print_stack(stack->mins);
    /* -3 1 5 */

    return 0;
}