#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = 0;
	stack_t *tmp = *stack;

	if (stack == 0)
		return;
	new_stack = (stack_t *)malloc(sizeof(stack_t));
	if (new_stack == 0)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	line_number++;
	new_stack->n = value;
	new_stack->next = 0;
	new_stack->prev = 0;
	if (*stack == 0)
	{
		*stack = new_stack;
		return;
	}
	while (tmp->prev != 0)
	{
		stack_t *next = tmp;

		tmp = tmp->prev;
		tmp->next = next;
	}
	new_stack->next = tmp;
	tmp->prev = new_stack;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == 0 || *stack == 0)
		return;
	line_number++;
	while (tmp->prev != 0)
	{
		stack_t *next = tmp;

		tmp = tmp->prev;
		tmp->next = next;
	}

	while (tmp != 0)
	{
		stack_t *prev = tmp;

		printf("%d\n", tmp->n);
		tmp = tmp->next;
		if (tmp != 0)
			tmp->prev = prev;
	}
}
