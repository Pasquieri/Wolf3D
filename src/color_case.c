#include "../include/wolf3d.h"

void	color_case(t_env *env)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = -1;
	while (++j < env->y)
	{
		i = -1;
		while (++i < env->x)
		{
			if (env->tab[j][i] == 0)
			{
				y = j * env->coef - 1;
				while (++y < (j * env->coef + env->coef))
				{
					x = i * env->coef - 1;
					while (++x < (i * env->coef + env->coef))
						put_pxl_img(env, x, y, 1);
				}
			}
		}
	}
}
