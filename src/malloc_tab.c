#include "../include/wolf3d.h"

int		malloc_tab(t_env *env)
{
	int i;

	i = 0;
	if (!(env->tab = (int **)malloc(sizeof(int *) * env->y)))
		return (error_message(3, env));
	while (i < env->x)
	{
		if (!(env->tab[i] = (int *)malloc(sizeof(int) * env->x)))
			return (error_message(3, env));
		i++;
	}
	return (0);
}