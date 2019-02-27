#include "../include/wolf3d.h"

int		wall_row(char *str, int nb_char, t_env *env) // verifie que les premiers et dernier char sont ne sont pas des cases vides
{
	if (str[0] == '0' && str[--nb_char] == '0')
		return (0);
	return (error_message(12, env));
}