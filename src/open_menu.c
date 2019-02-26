#include "../include/wolf3d.h"

void	open_menu(t_env *env)
{

	int 	blue_color;
 	int 	white_color;
	int 	red_color;
	int 	play_color;
	int 	exit_color;

	if (env->menu_select == 2)
		env->menu_select = 1;

	blue_color = 0x64F0F0;
	white_color = 0xFFFFFF;
	red_color = 0x510916;

	play_color = blue_color;
	exit_color = white_color;
	if (env->menu_select == 1)
	{
		play_color = white_color;
		exit_color = red_color;
	}

	mlx_put_image_to_window(env->mlx, env->win, env->imgmenu, 0, 0);

	mlx_string_put(env->mlx, env->win, 530, 330, white_color,
			"-- WOLF3D --");

	mlx_string_put(env->mlx, env->win, 570, 530, play_color,
			"Jouer");

	mlx_string_put(env->mlx, env->win, 570, 630, exit_color,
			"Quitter");

}
