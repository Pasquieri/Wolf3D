#include "../include/wolf3d.h"

void	put_pxl_img(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l2;
	if (color == 0)
	{
		env->img_str2[i] = (char)255;
		env->img_str2[i + 1] = (char)255;
		env->img_str2[i + 2] = (char)255;
	}
	else if (color == 1)
	{
		env->img_str2[i] = (char)10;
		env->img_str2[i + 1] = (char)170;
		env->img_str2[i + 2] = (char)213;
	}
}
