#include "../include/wolf3d.h"

void	color_case(t_env *env, t_map map)
{
	int		i;
	float	x;
	float	y;
	float	tmp_y;
	float	tmp_x;

	i = 0;
	while (map.map[i])
	{
		if (map.map[i] == '1')
		{
			y = (i / env->x + 1) * env->coef;
			tmp_y = y + env->coef;
			while (y < tmp_y)
			{
				x = (i % env->x) * env->coef + env->coef;
				tmp_x = x + env->coef;
				while (x < tmp_x)
				{
					put_pxl_img(env, x, y, 1);
					x++;
				}
				y++;
			}
		}
		i++;
	}
}
