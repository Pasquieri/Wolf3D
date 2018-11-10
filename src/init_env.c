#include "../include/wolf3d.h"

void	init_env(t_env *env, t_map *map)
{
	env->x = map->x;
	env->y = map->y;
	env->coef = 250 / (env->x + env->y);
	env->map = 1;
}
