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
}
