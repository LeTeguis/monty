#include "monty.h"

int printferr(int erreur, char *message, char *sup)
{
	if (erreur)
	{
		fprintf(stderr, "%s%s\n", message, sup);
		exit(EXIT_FAILURE);
	}
	return (erreur);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	 while (s1[i] != '\0' && s2[i] != '\0')
	 {
		 if (s1[i] != s2[i])
			 return (s1[i] - s2[i]);
		 i++;
	 }
	 return (s1[i] - s2[i]);
}
