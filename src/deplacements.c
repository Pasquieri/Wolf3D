#include "../include/wolf3d.h"

static int	check_wall(double xa, double ya, t_env *env)
{
	int	x;
	int	y;

/*	x = env->perso_x;
	while (x <= env->perso_x + xa)
	{
		y = env->perso_y;
		while (y <= env->perso_y + ya)
		{
			if (env->tab[y / env->coef][x / env->coef] == 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);*/
	x = env->perso_x + round(xa);
	y = env->perso_y + round(ya);
	if (env->tab[y / env->coef][x / env->coef] != 0)
		return (0);
	else
		return (1);
}

static int	init_angle(int d_regard)
{
	int	angle;

	angle = 0;
	if (d_regard >= 0 && d_regard < 90)
		angle = d_regard;
	else if (d_regard >= 90 && d_regard < 180)
		angle = 180 - d_regard;
	else if (d_regard >= 180 && d_regard < 270)
		angle = d_regard - 180;
	else if (d_regard >= 270 && d_regard <= 360)
		angle = 360 - d_regard;
	return (angle);
}

static void	init_coef(int d_regard, int *coef_x, int *coef_y)
{
	if (d_regard >= 0 && d_regard < 90)
	{
		*coef_x = 1;
		*coef_y = -1;
	}
	else if (d_regard >= 90 && d_regard < 180)
	{
		*coef_x = -1;
		*coef_y = -1;
	}
	else if (d_regard >= 180 && d_regard < 270)
	{
		*coef_x = -1;
		*coef_y = 1;
	}
	else if (d_regard >= 270 && d_regard <= 360)
	{
		*coef_x = 1;
		*coef_y = 1;
	}
}

static void	depla_vertical(t_env *env, int key)
{
	double	xa;
	double	ya;
	int		coef_x;
	int		coef_y;
	int		angle;

	if (key == 125)
		angle = env->d_regard - 180;
	else
		angle = env->d_regard;
	if (angle < 0)
		angle = angle + 360;
	angle = angle % 360;
	init_coef(angle, &coef_x, &coef_y);
	xa = fabs(cos(angle * M_PI / 180) * 2);
	ya = fabs(sin(angle * M_PI / 180) * 2);
	xa = xa * coef_x;
	ya = ya * coef_y;
	if (check_wall(xa, ya, env) == 0)
	{
		env->perso_x = env->perso_x + round(xa);
		env->perso_y = env->perso_y + round(ya);
	}
}

static void	depla_horizontal(t_env *env, int key)
{
	double	xa;
	double	ya;
	int		coef_x;
	int		coef_y;
	int		angle;

	if (key == 123)
		angle = env->d_regard + 90;
	else
		angle = env->d_regard - 90;
	if (angle < 0)
		angle = angle + 360;
	angle = angle % 360;
	init_coef(angle, &coef_x, &coef_y);
	angle = init_angle(angle);
	xa = fabs(cos(angle * M_PI / 180) * 2);
	ya = fabs(sin(angle * M_PI / 180) * 2);
	xa = xa * coef_x;
	ya = ya * coef_y;
	if (check_wall(xa, ya, env) == 0)
	{
		env->perso_x = env->perso_x + round(xa);
		env->perso_y = env->perso_y + round(ya);
	}
}

void		deplacements(int key, t_env *env)
{
	int	x;
	int	y;

	x = env->perso_x;
	y = env->perso_y;
	if (key == 125 || key == 126)
		depla_vertical(env, key);
	else if (key == 123 || key == 124)
		depla_horizontal(env, key);
}
