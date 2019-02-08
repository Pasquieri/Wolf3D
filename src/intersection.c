#include "../include/wolf3d.h"

static int	verif_lim(float x2, float y2)
{
	if (x2 < 0. || y2 < 0.)
		return (1);
	return (0);
}

static int	verif_horizontal(float y2, t_env *env)
{
	int	j;

	j = round(y2) / env->coef;
	if (j != (env->perso_y / env->coef))
		return (1);
	else
		return (0);
}

t_coord			intersection_horizontal(t_env *env)
{
	int		ya;
	float	x2;
	float	y2;
	int		coef_y;
	int		coef_x;
	t_coord	coord;
	int		lim;

	lim = env->x * env->coef;
	ya = 0;
	x2 = env->perso_x;
	y2 = env->perso_y;
	coef_y = 1;
	coef_x = 1;
	if (env->angle > 0. && env->angle < 180.)
		coef_y = -1;
	if (env->angle > 180. && env->angle < 360.)
		coef_x = -1;
	while (ya < env->coef && x2 < lim && y2 < lim
			&& (env->tab[(int)round(y2)
				/ env->coef][(int)round(x2) / env->coef]) != 0)
	{
		y2 = y2 + coef_y;
		x2 = env->perso_x + ((ya * coef_x) / tan(env->angle * M_PI / 180));
		if (verif_horizontal(y2, env) == 1)
			ya = env->coef;
		if (verif_lim(x2, y2) == 1)
			ya = env->coef;
		ya++;
	}
	coord.x = (x2);
	coord.y = (y2);
	return (coord);
}

static int	verif_vertical(float x2, t_env *env)
{
	int	i;

	i = round(x2) / env->coef;
	if (i != (env->perso_x / env->coef))
		return (1);
	else
		return (0);
}

t_coord			intersection_vertical(t_env *env)
{
	int		xa;
	float	x2;
	float	y2;
	int		coef_x;
	int		coef_y;
	t_coord	coord;
	int		lim;

	xa = 0;
	lim = env->coef * env->x;
	x2 = env->perso_x;
	y2 = env->perso_y;
	coef_x = 1;
	coef_y = 1;
	if (env->angle > 90. && env->angle < 270.)
		coef_x = -1;
	if  (!(env->angle > 90. && env->angle < 270.))
		coef_y = -1; //
//	printf("\nxa : %d, lim : %d, x2 : %f, y2 : %f, coef_x :%d coef_y : %d env->angle : %f env->coef : %d\n", xa,lim, x2, y2, coef_x, coef_y, env->angle, env->coef);
	while (xa < env->coef && x2 < lim && y2 < lim
			&& (env->tab[(int)round(y2) 
				/ env->coef][(int)round(x2) / env->coef]) != 0)
	{
		x2 = x2 + coef_x;
		y2 = env->perso_y + ((xa * coef_y) * tan(env->angle * M_PI / 180));
		if (verif_vertical(x2, env) == 1)
			xa = env->coef;
		if (verif_lim(x2, y2) == 1)
			xa = env->coef;
		xa++;
	}
	coord.x = (x2);
	coord.y = (y2);
	return (coord);
}
