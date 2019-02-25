#include "../include/wolf3d.h"

void	open_menu(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->imgmenu, 0, 0);

	mlx_string_put(env->mlx, env->win, 530, 330, -1,
			"-- WOLF3D --");

	mlx_string_put(env->mlx, env->win, 570, 530, -1,
			"Text 1");

	mlx_string_put(env->mlx, env->win, 570, 630, -1,
			"Text 2");

	mlx_string_put(env->mlx, env->win, 570, 730, -1,
			"Text 3");
}