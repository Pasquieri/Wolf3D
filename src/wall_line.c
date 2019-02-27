#include "../include/wolf3d.h"

int		wall_line(char *str, t_env *env) // verifie que les premiers et dernier char sont ne sont pas des cases vides
{
	int		i;
	char	c;

	c = '0';
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\n' && str[i] != ' ')
			return (error_message(12, env));
		i++;
	}
	return (0);
}