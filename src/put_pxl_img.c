#include "../include/wolf3d.h"

void	put_pxl_img(t_env *env, float x, float y)
{
	int	i;

	i = 4 * x + y * env->s_l;
	env->img_str[i] = (char)255;
	env->img_str[i + 1] = (char)255;
	env->img_str[i + 2] = (char)255;
}
