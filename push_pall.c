#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = 0;
	stack_t *tmp = *stack;
	int erreur = argumentCorrect("push", 2);
	
	_argument.passed = 0;
	if (erreur == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		_argument.passed = 1;
		exit(EXIT_FAILURE);
	}
	if (erreur == 0 || stack == 0)
		return;
	_argument.passed = 1;
	new_stack = (stack_t *)malloc(sizeof(stack_t));
	if (new_stack == 0)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	line_number++;
	new_stack->n = atoi(_argument.argv[1]);
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
	int erreur = argumentCorrect("pall", 1);

	_argument.passed = 0;
	if (erreur == -1)
	{
		printf("L%u: usage: pall\n", line_number);
		_argument.passed = 1;
		exit(EXIT_FAILURE);
	}
	if (erreur == 0 || stack == 0 || *stack == 0)
		return;
	_argument.passed = 1;
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
