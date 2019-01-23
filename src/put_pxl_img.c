#include "../include/wolf3d.h"

void	put_pxl_img(t_env *env, int x, int y, int color)
{
	int	i;

	if (color < 5)
		i = 4 * x + y * env->s_l2;
	else
		i = 4 * x + y * env->s_l;
	if (color == 0)
	{
		env->img_str2[i] = (char)230;
		env->img_str2[i + 1] = (char)230;
		env->img_str2[i + 2] = (char)230;
	}
	else if (color == 1)
	{
		env->img_str2[i] = (char)113;
		env->img_str2[i + 1] = (char)170;
		env->img_str2[i + 2] = (char)10;
	}
	else if (color == 2)
	{
		env->img_str2[i] = (char)200;
		env->img_str2[i + 1] = (char)220;
		env->img_str2[i + 2] = (char)254;
	}
	else if (color == 3)
	{
		env->img_str2[i] = (char)159;
		env->img_str2[i + 1] = (char)161;
		env->img_str2[i + 2] = (char)255;
	}
	else if (color == 4)
	{
		env->img_str2[i] = (char)0;
		env->img_str2[i + 1] = (char)0;
		env->img_str2[i + 2] = (char)0;
	}
	else if (color == 5) // mur
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
	else if (color == 8)
	{
		env->img_str[i] = (char)0;
		env->img_str[i + 1] = (char)0;
		env->img_str[i + 2] = (char)0;
	}
}
