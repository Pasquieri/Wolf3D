#include "../include/wolf3d.h"

void	quadrillage(t_env *env)
{
	int		i;
	int		j;
	t_coord	coord1;
	t_coord	coord2;
	t_coord	coord3;

	j = 1;
	while (j <= env->y + 1)
	{
		coord1.y = j * env->coef;
		coord2.y = j * env->coef;
		i = 1;
		while (i <= env->x + 1)
		{
			coord1.x = i * env->coef;
			coord2.x = (i + 1) * env->coef;
			if ((i + 1) <= env->x + 1)
				ft_trace_seg(env, coord1, coord2);
			if (j > 1)
			{
				coord3.x = coord1.x;
				coord3.y = coord1.y - env->coef;
				ft_trace_seg(env, coord1, coord3);
			}
			i++;
		}
		j++;
	}
}