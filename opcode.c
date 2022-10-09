#include "monty.h"

instruction_t instructions[OPCODE_SIZE];
stack_t *stack_ = 0;
int value = 0;
Argument _argument;

/**
 * setInstruction - set
 *
 * @index: int
 * @opcode: name
 * @f: function
 *
 * Return: nothing
 */
void setInstruction(int index, char *opcode,
		void (*f)(stack_t **stack, unsigned int line_number))
{
	if (index >= 0 && index < OPCODE_SIZE)
	{
		instructions[index].opcode = opcode;
		instructions[index].f = f;
	}
}

/**
 * defineInstruction - define
 *
 * Return: nothing
 */
void defineInstruction(void)
{
	setInstruction(0, "push", push);
	setInstruction(1, "pall", pall);
}

/**
 * argumentCorrect - verifie correct argument
 *
 * @nom: str
 * @nbr_param: leng
 *
 * Return: 0, 1 or -1
 */
int argumentCorrect(char *nom, int nbr_param)
{
	if (_argument.argv != 0 && _argument.argv[0])
	{
		if (_strcmp(_argument.argv[0], nom) == 0)
		{
			if (_argument.argc == nbr_param)
				return (1);
			return (-1);
		}
	}
	return (0);
}
