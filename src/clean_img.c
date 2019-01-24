#include "../include/wolf3d.h"

void	clean_img(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 200)
	{
		x = 0;
		while (x <= 200)
		{
			put_pxl_img(env, x, y, 4);
			x++;
		}
		y++;
	}
	y = 0;
	x = 0;
	while (y < (1200 * 870))
	{
		env->img_str[x] = (char)0;
		env->img_str[x + 1] = (char)0;
		env->img_str[x + 2] = (char)0;
		x = x + 4;
		y++;
	}
}
