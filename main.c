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
				int error = 1;
				size_t arg;

				_argument.argv = _getline_arg(fichier, &arg);
				_argument.argc = arg;
				if (_argument.argv == 0)
				{
					break;
				}
				for (indice = 0; indice < OPCODE_SIZE; indice++)
				{
					instructions[indice].f(&stack_, ligne + 1);
					if (_argument.passed)
					{
						error = 0;
						break;
					}
				}

				if (error)
				{
					printf("L%d: unknown instruction %s\n", ligne + 1, _argument.argv[0]);
					_free(_argument.argv);
					exit(EXIT_FAILURE);
					return (0);
				}
				_free(_argument.argv);
				ligne++;
			}
		}
	}
	return (0);
}
