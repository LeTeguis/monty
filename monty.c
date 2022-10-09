#include "monty.h"

int isMontyFile(char *filename)
{
	int leng = 0;

	if (filename == 0)
		return (0);
	while (filename[leng])
		leng++;
	if (leng <= 1)
		return (0);
	if ((filename[leng - 1] == 'm' || filename[leng - 1] == 'M')
			&& filename[leng -2] == '.')
		return (1);
	return (0);
}
