#include "../include/wolf3d.h"

int		verif_valeur(char *str, t_env *env)
{
	int		valeur;

	valeur = ft_atoi(str);
	if (valeur == 0)
		return (error_message(10, env));
	if (valeur > 10000)
		return (error_message(9, env));
	return (valeur);
}