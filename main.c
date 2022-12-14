#include "monty.h"

/**
 * core - core
 *
 * @fichier: FILE
 * @ligne: int
 *
 * Return: 0 or 1
 */
int core(FILE *fichier, int ligne)
{
	unsigned int indice = 0;
	int error = 1;
	int arg;

	_argument.argv = _getline_arg(fichier, &arg);
	if (arg == -1)
		return (0);
	_argument.argc = arg;
	if (_argument.argv == 0)
		return (2);
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
		fprintf(stderr, "L%d: unknown instruction %s\n",
				ligne + 1, _argument.argv[0]);
		_free(_argument.argv, 0);
		exit(EXIT_FAILURE);
		return (0);
	}
	_free(_argument.argv, 0);
	_argument.argc = 0;
	return (1);
}
/**
 * main - entry point
 *
 * @argc: leng
 * @argv: arg
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (!printferr(argc != 2, "USAGE: monty file", ""))
	{
		FILE *fichier = fopen(argv[1], "r");

		if (!printferr(fichier == 0, "Error: Can't open file ", argv[1]))
		{
			int ligne = 0;

			defineInstruction();
			while (1)
			{
				int error = core(fichier, ligne);

				if (error == 0)
					break;
				ligne++;
			}
		}
	}
	return (0);
}
