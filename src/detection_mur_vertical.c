#include "../include/wolf3d.h"

int	verif_ver(t_env *env, t_coord *coord)
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
		printf("hors zone !\n");
		return (-1);
	}
	i = round(coord->x) / env->coef;
	j = round(coord->y) / env->coef;
	if (env->tab[j][i] == 0)
		return (1);
	i = round(coord->x + 1) / env->coef;
	if (env->tab[j][i] == 0)
		return (1);
	i = round(coord->x - 1) / env->coef;
	if (env->tab[j][i] == 0)
		return (1);
	else
		return (0);
}

int	coef_ver(t_env *env, int *coef_x, int *coef_y)
{
	*coef_x = 1;
	*coef_y = 1;
	if (env->d_regard > 90 && env->d_regard < 270)
		*coef_x = -1;
	if (!(env->d_regard > 90 && env->d_regard <= 270))
		*coef_y = -1;
	return (0);
}

void	init_var_ver(t_env *env, float *ya, float *xa, t_coord *coord2)
{
	int	coef;

	coef = 1;
	if (env->d_regard == 0 || env->d_regard == 180)
	{
		*ya = 0;
		*xa = env->coef;
		env->d_regard == 180 ? coef = - 1 : coef;
		coord2->x = env->perso_x + (env->perso_x % env->coef) * coef;
		coord2->y = env->perso_y;
	}
	else if (env->d_regard == 90 || env->d_regard == 270)
	{
		*ya = env->coef;
		*xa = 0;
		env->d_regard == 90 ? coef = - 1 : coef;
		coord2->x = env->perso_x;
		coord2->y = env->perso_y + (env->perso_y % env->coef) * coef;
	}
	else
	{
		*xa = env->coef;
		*ya = env->coef * tan(env->d_regard * M_PI / 180);
		*coord2 = intersection_vertical(env);
	}
}
