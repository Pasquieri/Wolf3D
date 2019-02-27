#include "../include/wolf3d.h"

int		verif_char(char *str, t_env *env) //verif que *str cest bien composer de char valides
{
	int		x;
	char	nombre[3];

	nombre[2] = '\0';
	x = 0;
	while (str[x])
	{
		if (str[x + 1] != '\0')
		{
			nombre[0] = str[x];
			nombre[1] = str[x + 1];
			if (str[x] != ' ' && str[x + 1] != ' ')
				return (error_message(7, env));
		}
		if ((str[x] != '\0') && (str[x] != ' ') && ((str[x] >= 48)
					&& (str[x] <= 39) && (str[x] != '\n')
					&& (str[x] != '\t')))
			return (error_message(7, env));
		x++;
	}
	return (x);
}