#include "monty.h"

int main(int argc, char *argv[])
{
	if (!printferr(argc != 2, "USAGE: monty file", ""))
	{
		FILE *fichier = fopen(argv[1],"r");

		if (!printferr(fichier == 0, "Error: Can't open file ", argv[1]))
		{
			int ligne = 0;

			defineInstruction();
			while (1)
			{
				unsigned int indice = 0;
				size_t arc = 0;
				char **arg = _getline_arg(fichier, &arc);
				int error = 1;

				if (arg == 0)
				{
					break;
				}
				for (indice = 0; indice < OPCODE_SIZE; indice++)
				{
					if (_strcmp(arg[0], instructions[indice].opcode) == 0)
					{
						if (_strcmp(arg[0], "push") == 0)
						{
							if (arc != 2)
							{
								printf("L%d: usage: push integer\n", ligne + 1);
								exit(EXIT_FAILURE);
								return (0);
							}
							value = atoi(arg[1]);
						}
						instructions[indice].f(&stack_, ligne + 1);
						error = 0;
						break;
					}
				}

				if (error)
				{
					printf("L%d: unknown instruction %s\n", ligne + 1, arg[0]);
					_free(arg);
					exit(EXIT_FAILURE);
					return (0);
				}
				_free(arg);
				ligne++;
			}
		}
	}
	return (0);
}
