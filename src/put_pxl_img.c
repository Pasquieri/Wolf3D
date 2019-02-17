#include "../include/wolf3d.h"

static void	win_img(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l;
	if (color == 5) // mur
	{
		env->img_str[i] = (char)130;
		env->img_str[i + 1] = (char)227;
		env->img_str[i + 2] = (char)130;
	}
	else if (color == 6) // ciel
	{
		env->img_str[i] = (char)240;
		env->img_str[i + 1] = (char)130;
		env->img_str[i + 2] = (char)44;
	}
	else if (color == 7) // sol
	{
		env->img_str[i] = (char)93;
		env->img_str[i + 1] = (char)145;
		env->img_str[i + 2] = (char)190;
	}
}

static void	map_img(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l2;
	if (color == 0)
	{
		env->img_str2[i] = (char)230; // quadrillage blanc
		env->img_str2[i + 1] = (char)230;
		env->img_str2[i + 2] = (char)230;
	}
	else if (color == 1) // case mini map vert
	{
		env->img_str2[i] = (char)113;
		env->img_str2[i + 1] = (char)170;
		env->img_str2[i + 2] = (char)10;
	}
/*	else if (color == 2) // rose pale
	{
		env->img_str2[i] = (char)200;
		env->img_str2[i + 1] = (char)220;
		env->img_str2[i + 2] = (char)254;
	}*/
	else if (color == 3) // cercle perso rose
	{
		env->img_str2[i] = (char)159;
		env->img_str2[i + 1] = (char)161;
		env->img_str2[i + 2] = (char)255;
	}
}

void		put_pxl_img(t_env *env, int x, int y, int color)
{
	if (color < 5)
		map_img(env, x, y, color);
	else
		win_img(env, x, y, color);
}
