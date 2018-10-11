#include "../include/wolf3d.h"

void	quadrillage(t_env *env)
{
	int		i;
	int		j;
	t_coord	coord1;
	t_coord	coord2;

	j = 1;
	while (j < env->y)
	{
		coord1.y = j * env->coef;
		coord2.y = j * env->coef;
		i = 1;
		while (i < env->x)
		{
			coord1.x = i * env->coef;
			coord2.x = (i + 1) * env->coef;
			ft_trace_seg(env, coord1, coord2);
			i++;
		}
		j++;
	}
}
