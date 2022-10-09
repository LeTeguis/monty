#include "monty.h"

/**
 * _atoi - convert
 *
 * @str: str
 * @error: get error
 *
 * Return: int
 */
int _atoi(char *str, int *error)
{
	int digit = 0;

	if (*error == 0 || str == 0)
		return (0);
	while (str[digit])
	{
		if (str[digit] < '0' || str[digit] > '9')
		{
			*error = -1;
			return (0);
		}
		digit++;
	}
	*error = 1;
	return (atoi(str));
}

/**
 * push - push
 *
 * @stack: stack
 * @line_number: int
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = 0;
	stack_t *tmp = *stack;
	int erreur = argumentCorrect("push", 2);
	int valeur = _atoi(_argument.argv[1], &erreur);

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
	new_stack->n = valeur;
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

/**
 * pall - print
 *
 * @stack: stack
 * @line_number: ui
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int erreur = argumentCorrect("pall", 0);

	_argument.passed = 0;
	if (erreur == 0)
		return;
	_argument.passed = 1;
	if (stack == 0 || *stack == 0)
		return;
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
	line_number++;
}
