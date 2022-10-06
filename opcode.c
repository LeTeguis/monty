#include "monty.h"

instruction_t instructions[OPCODE_SIZE];
stack_t *stack_;
int value;

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
