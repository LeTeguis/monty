#include "monty.h"

instruction_t instructions[OPCODE_SIZE];
stack_t *stack_;
int value;
Argument _argument;

void setInstruction(int index, char *opcode, void (*f)(stack_t **stack, unsigned int line_number))
{
	if (index >= 0 && index < OPCODE_SIZE)
	{
		instructions[index].opcode = opcode;
		instructions[index].f = f;
	}
}

void defineInstruction()
{
	setInstruction(0, "push", push);
	setInstruction(1, "pall", pall);
}

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
