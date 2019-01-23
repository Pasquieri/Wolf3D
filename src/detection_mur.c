#include "../include/wolf3d.h"

static void	ft_round(t_coord *coord)
{
	coord->x = round(coord->x);
	coord->y = round(coord->y);
}

int	detection_mur(t_env *env)
{
	float	xa;
	float	ya;
	t_coord	coord1;
	t_coord	coord2;
	int		coef_x;
	int		coef_y;
	double	d;
	t_coord	coord_perso; //

	printf("d_regard : %d\n", env->d_regard); //
	coord_perso.x = env->perso_x; //
	coord_perso.y = env->perso_y; //
	init_var_hor(env, &ya, &xa, &coord1);
	coef_hor(env, &coef_x, &coef_y);
	while (verif_hor(env, &coord1) == 0)
	{
		coord1.x += (xa * coef_x);
		coord1.y += (ya * coef_y);
	}
	d = sqrt(pow(env->perso_x - coord1.x, 2) + pow(env->perso_y - coord1.y, 2));
	ft_round(&coord1);
	init_var_ver(env, &ya, &xa, &coord2);
	coef_ver(env, &coef_x, &coef_y);
	while (verif_ver(env, &coord2) == 0)
	{
		coord2.x += (xa * coef_x);
		coord2.y += (ya * coef_y);
	}
	ft_round(&coord2);
	ft_trace_seg(env, coord_perso, coord1); //
	ft_trace_seg(env, coord_perso, coord2); //
	if (d < sqrt(pow(env->perso_x - coord2.x, 2) + pow(env->perso_y - coord2.y, 2)))
		return (1);
	else
		return (2);
}

/* renvoyer les coords de l'intersection avec le mur ?  + distance  ? */
