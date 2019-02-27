#include "../include/wolf3d.h"

int		compte_char(char *str, char c) // cette fonction compte le nombre de char de la map a charger dans un tab
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		x++;
		i++;
	}
	return (x);
}
