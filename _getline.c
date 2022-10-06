#include "monty.h"

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
			n++;
		i++;
	}
	return (n);
}

char *getWordI(char *line, size_t index)
{
	size_t n = 0;
	size_t i = 0;
	int prev = 0;
	int actu = 0;
	int deb = -1;
	size_t size_ = 0;
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
	{
		return (0);
	}
	i = deb;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			break;
		i++;
	}
	size_ = i - deb;
	word = (char *)malloc(sizeof(char) * (size_));
	if (word == 0)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return (0);
	}
	for (i = 0; i < size_; i++)
	{
		word[i] = line[deb + i];
	}
	word[size_] = '\0';
	return (word);
}

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

char **_getline_arg(FILE *file, size_t *arc)
{
	char *linestr;
	size_t n = 0;
	size_t nbr_arg = 0;
	size_t i = 0;
	char **arg;

	if (getline(&linestr, &n, file) == -1)
		return (0);
	nbr_arg = _nbrarg(linestr);
	if (nbr_arg == 0)
		return (0);
	arg = (char **)malloc(sizeof(char *) * (nbr_arg + 1));
	if (arg == 0)
	{
		printf("Error: malloc failed\n");
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
	*arc = nbr_arg;
	return (arg);
}
