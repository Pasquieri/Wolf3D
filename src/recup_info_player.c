#include "../include/wolf3d.h"

int		recup_info_player(char *str, char c) // recup et verif les info des coordonee du player mis dans la fichier .map
{
	int		i;
	int		x;
	int		y;

	if (c == 'x')
	{
		i = 0;
		while(str[i] != '(')
		{
			if (str[i] == '\0')
				return (-1);
			str[i] = ' ';
			i++;
		}
		str[i] = ' ';
		x = ft_atoi(str);
		while (str[i] != ',')
		{
			if (str[i] == '\0')
				return (-1);
			str[i] = ' ';
			i++;
		}
		str[i] = ' ';
		if (x > 0)
			return (x);
		else
			return (-1);
	}
	else if (c == 'y')
	{
		y = ft_atoi(str);
		if (y > 0)
			return (y);
		else
			return (-1);
	}
	return (-1);
}