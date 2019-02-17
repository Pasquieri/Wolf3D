#include "../include/wolf3d.h"

void	init_var_hor(t_env *env, double *ya, double *xa, t_coord *coord1)
{
	int	coef;

	coef = 1;
	if (env->angle == 0. || env->angle == 180.)
	{
		*ya = 0;
		*xa = env->coef;
		env->angle == 180. ? coef = - 1 : coef;
		coord1->x = env->perso_x + (env->perso_x % env->coef) * coef;
		coord1->y = env->perso_y;
	}
	else if (env->angle == 90. || env->angle == 270.)
	{
		*ya = env->coef;
		*xa = 0;
		env->angle == 90. ? coef = - 1 : coef;
		coord1->x = env->perso_x;
		coord1->y = env->perso_y + (env->perso_y % env->coef) * coef;
	}
	else
	{
		*ya = env->coef;
		*xa = env->coef / tan(env->angle * M_PI / 180);
		*coord1 = intersection_horizontal(env);
	}
}

int		coef_hor(t_env *env, int *coef_x, int *coef_y)
{
	*coef_x = 1;
	*coef_y = 1;
	if (env->angle > 0. && env->angle < 180.)
		*coef_y = -1;
	if (env->angle >= 180. && env->angle < 360.)
		*coef_x = -1;
	return (0);
}

int		verif_hor(t_env *env, t_coord *coord) //27 lignes
{
	int	i;
	int	j;
	int	lim;

	lim = env->x * env->coef;
	if (coord->x > lim || coord->y > lim || coord->x < 0 || coord->y < 0)
	{
		coord->x > lim ? coord->x = lim : coord->x;
		coord->y > lim ? coord->y = lim : coord->y;
		coord->x < 0 ? coord->x = 0 : coord->x;
		coord->y < 0 ? coord->y = 0 : coord->y;
		return (-1);
	}
	i = round(coord->x) / env->coef;
	j = (round(coord->y)) / env->coef;
	if (i < env->x && j < env->x)
	{
		if (env->tab[j][i] == 0)
			return (1);
		j = (round(coord->y) + 1) / env->coef;
		if (env->tab[j][i] == 0)
			return (1);
		j = (round(coord->y) - 1) / env->coef;
		if (env->tab[j][i] == 0)
			return (1);
	}
	return (0);
}
