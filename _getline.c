#include "monty.h"

/**
 * _nbrarg - get
 *
 * @line: str
 *
 * Return: count
 */
size_t _nbrarg(char *line)
{
	size_t n = 0;
	size_t i = 0;
	int prev = 0;
	int actu = 0;

	while (line[i])
	{
		if (line[i] == '\0' || line[i] == '\n')
			break;
		prev = actu;
		actu = (line[i] == ' ') ? 0 : 1;

		if (actu == 1 && prev == 0)
		{
			n++;
		}
		i++;
	}
	return (n);
}
/**
 * getWordI - get
 *
 * @line: str
 * @index: size_t
 *
 * Return: word
 */
char *getWordI(char *line, size_t index)
{
	size_t n = 0;
	size_t i = 0;
	size_t j = 0;
	int prev = 0;
	int actu = 0;
	int deb = -1;
	char *word = 0;

	while (line[i])
	{
		if (line[i] == '\0' || line[i] == '\n')
			break;
		prev = actu;
		actu = (line[i] == ' ') ? 0 : 1;
		if (actu == 1 && prev == 0)
			n++;
		if (n - 1 == index)
		{
			deb = i;
			break;
		}
		i++;
	}
	if (deb == -1)
		return (0);
	i = deb;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			break;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (i - deb));
	if (printferr(word == 0, "Error: malloc failed", ""))
		return (0);
	for (j = 0; j <= i - deb; j++)
		word[j] = (j == i - deb) ? '\0' : line[deb + j];
	return (word);
}

/**
 * _free - delete
 *
 * @arg: str str
 *
 * Return: 0
 */
int _free(char **arg)
{
	if (arg != 0)
	{
		int i = 0;

		while (arg[i])
			free(arg[i++]);
		free(arg);
	}
	return (0);
}
/**
 * _getline_arg - get
 *
 * @file: File
 * @arc: size_t
 *
 * Return: argument or null
 */
char **_getline_arg(FILE *file, int *arc)
{
	char *linestr;
	size_t n = 0;
	size_t nbr_arg = 0;
	size_t i = 0;
	char **arg;

	*arc = 0;
	if (getline(&linestr, &n, file) == -1)
	{
		*arc = -1;
		return (0);
	}
	nbr_arg = _nbrarg(linestr);
	if (nbr_arg == 0)
		return (0);
	arg = (char **)malloc(sizeof(char *) * (nbr_arg + 1));
	if (arg == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return (0);
	}
	for (i = 0; i < nbr_arg; i++)
	{
		char *word = getWordI(linestr, i);

		if (word == 0)
		{
			_free(arg);
			free(linestr);
			return (0);
		}
		arg[i] = word;
	}
	arg[nbr_arg] = 0;
	free(linestr);
	*arc = (int)nbr_arg;
	return (arg);
}
