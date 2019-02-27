#include "../include/wolf3d.h"

int		tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		i--;
	return (i);
}