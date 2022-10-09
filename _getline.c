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
char *getWordI(char *line, int *index)
{
	int n = 0;
	int i = 0;
	int j = 0;
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
		if (n - 1 == *index)
		{
			deb = i;
			break;
		}
		i++;
	}
	if (deb == -1)
	{
		*index = -1;
		return (0);
	}
	i = deb;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			break;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (i - deb + 1));
	if (word != 0)
		for (j = 0; j <= i - deb; j++)
			word[j] = (j == i - deb) ? '\0' : line[deb + j];
	return (word);
}

/**
 * _free - delete
 *
 * @arg: str str
 * @line: str
 *
 * Return: 0i
 */
int _free(char **arg, char *line)
{
	if (arg != 0)
	{
		int i = 0;

		while (arg[i])
		{
			free(arg[i++]);
		}
		free(arg);
	}
	if (line != 0)
	{
		free(line);
	}
	arg = 0;
	line = 0;
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
	char *linestr = 0;
	size_t n = 0;
	int i = 0;
	char **arg = 0;

	if (getline(&linestr, &n, file) == -1)
	{
		*arc = -1;
		_free(0, linestr);
		return (0);
	}
	*arc = (int)_nbrarg(linestr);
	if (*arc == 0)
	{
		_free(0, linestr);
		return (0);
	}
	arg = (char **)malloc(sizeof(char *) * (*arc + 1));
	if (arg == 0)
	{
		_free(0, linestr);
		printferr(1, "Error: malloc failed", "");
		return (0);
	}
	for (i = 0; i < *arc; i++)
	{
		char *word = getWordI(linestr, &i);

		if (word == 0)
		{
			_free(arg, linestr);
			printferr(i == -1, "Error: malloc failed", "");
			break;
		}
		arg[i] = word;
	}
	if (arg != 0)
		arg[*arc] = 0;
	return (arg);
}
