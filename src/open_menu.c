#include "../include/wolf3d.h"

static void	affiche_menu_valide(t_env *env, t_color_menu *color_menu)
{
	mlx_string_put(env->mlx, env->win, 380, 330, color_menu->white_color,
				"WOLF3D : appuyer sur espace pour selectionner");

		mlx_string_put(env->mlx, env->win, 560, 530, color_menu->play_color,
				"Jouer");

		mlx_string_put(env->mlx, env->win, 560, 560, color_menu->map1_color,
				"Niveau 1");

		mlx_string_put(env->mlx, env->win, 560, 590, color_menu->map2_color,
				"Niveau 2");

		mlx_string_put(env->mlx, env->win, 560, 620, color_menu->map3_color,
				"Niveau 3");

		mlx_string_put(env->mlx, env->win, 560, 650, color_menu->exit_color,
				"Quitter");
}

static void	affiche_menu_invalide(t_env *env, t_color_menu *color_menu)
{
	mlx_string_put(env->mlx, env->win, 495, 330, color_menu->white_color,
				"WOLF3D : map invalide");

		mlx_string_put(env->mlx, env->win, 560, 530, color_menu->map1_color,
				"Niveau 1");

		mlx_string_put(env->mlx, env->win, 560, 560, color_menu->map2_color,
				"Niveau 2");

		mlx_string_put(env->mlx, env->win, 560, 590, color_menu->map3_color,
				"Niveau 3");

		mlx_string_put(env->mlx, env->win, 560, 620, color_menu->exit_color,
				"Quitter");
}

void	open_menu(t_env *env)
{
	t_color_menu 	color_menu;

	color_menu.blue_color = 0x64F0F0;
	color_menu.white_color = 0xFFFFFF;
	color_menu.green_color = 0x00FF33;

	color_menu.play_color = color_menu.white_color;
	color_menu.exit_color = color_menu.white_color;
	color_menu.map1_color = color_menu.white_color;
	color_menu.map2_color = color_menu.white_color;
	color_menu.map3_color = color_menu.white_color;

	//if (env->map_entree != 0 && env->menu_select <= 1)
	//	env->menu_select = 2;	
		
	if (env->menu_select == 1)
		color_menu.play_color = color_menu.green_color;
	else if (env->menu_select == 2)
		color_menu.map1_color = color_menu.green_color;
	else if (env->menu_select == 3)
		color_menu.map2_color = color_menu.green_color;
	else if (env->menu_select == 4)
		color_menu.map3_color = color_menu.green_color;
	else if (env->menu_select == 5)
		color_menu.exit_color = color_menu.green_color;

	mlx_put_image_to_window(env->mlx, env->win, env->imgmenu, 0, 0);
	if (env->map_entree == 0)
		affiche_menu_valide(env, &color_menu);	
	else
		affiche_menu_invalide(env, &color_menu);
}
