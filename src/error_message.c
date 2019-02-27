#include "../include/wolf3d.h"

int 	error_message(int num, t_env *env) //Cette fonction affiche les messages d'erreurs et retourn (-1) pour arreter le programme
{
	ft_putstr("Erreur : ");
	if (env->detail > 0)
	{
		if (num == 1)
			ft_putstr("Un parametre est attendu");
		else if (num == 2)
			ft_putstr("Ouverture de la map impossible");
		else if (num == 3)
			ft_putstr("Erreur de malloc");
		else if (num == 4)
			ft_putstr("Le nombre de colonnes (y) indique est incorrect");
		else if (num == 5)
			ft_putstr("Le nombre de lignes (x) indique est incorrect");
		else if (num == 6)
			ft_putstr("La premiere ligne de la map doit etre \"player : (X,X);\"");
		else if (num == 7)
			ft_putstr("Un des caracteres de la map est incompatible");
		else if (num == 8)
			ft_putstr("Le nombre de caracteres n'est pas le meme pour toutes les lignes");
		else if (num == 9)
			ft_putstr("Le nombre de x et de y indique est trop elevee (10000 max)");
		else if (num == 10)
			ft_putstr("Le nombre indique est egal a zero ou n'existe pas");
		else if (num == 11)
			ft_putstr("La map n'a pas de case vide");
		else if (num == 12)
			ft_putstr("La map n'est pas cadre par des murs");
		else if (num == 13)
			ft_putstr("La map est vide");
		else if (num == 14)
			ft_putstr("Les coordonnees du player ne sont pas valides");
		else if (num == 15)
			ft_putstr("Le joueur est place dans un mur");
	}
	else if (env->detail == 0)
		ft_putstr("map invalide");
	ft_putchar('\n');
	return (-1);
}