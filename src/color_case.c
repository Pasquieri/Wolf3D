#include "../include/wolf3d.h"

void	color_case(t_env *env)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < env->y)
	{
		j = -1;
		while (++j < env->x)
		{
			if (env->tab[i][j] == 1)
			{
				y = i * env->coef - 1;
				while (++y < (i * env->coef + env->coef))
				{
					x = j * env->coef + env->coef - 1;
					while (++x < (j * env->coef + 2 * env->coef))
						put_pxl_img(env, x, y, 1);
				}
			}
		}
	}
}
