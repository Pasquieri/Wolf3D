/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:57:03 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/25 13:04:21 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void	rotation_regard(t_env *env, int key)
{
	if (key == 69 || key == 27)
		env->d_regard += 1;
	else if (key == 78 || key == 24)
		env->d_regard -= 1;
	if (key == 123)
		env->d_regard += 5;
	else if (key == 124)
		env->d_regard -= 5;
	else if (key == 125 && env->h_regard > (870 / 2 - 200))
		env->h_regard -= 7;
	else if (key == 126 && env->h_regard < (870 / 2 + 200))
		env->h_regard += 7;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
}

static int	deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(0);
		//123-124-125-126 Arrow / 48 Tab / 49 Space
	if (key == 69 || key == 27 || key == 24 || key == 78 || key == 46 || key == 49
		|| (key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
	{
		if (key == 49 && !env->menu) {
			open_menu(env);
			env->menu = 1;
			return (0);
		}
		else if (key == 49 && env->menu)
			env->menu = 0;
		else if (((key >= 0 && key <= 2) || key == 13) && !env->menu)
			deplacements(key, env);
		else if ((key == 69 || key == 27 || key == 78 || key == 24
				|| (key >= 123 && key <= 126)) && !env->menu)
			rotation_regard(env, key);
		else if (key >= 123 && key <= 126 && env->menu == 1)
		{
			if (env->menu_select == 0 || !env->menu_select)
				env->menu_select = 1;
			else if (env->menu_select == 1)
				env->menu_select = 0;
			open_menu(env);
		}
		if (!env->menu)
		{
			clean_img(env);
			affichage_mur(env);
			color_case(env);
			quadrillage(env);
			print_cercle(env);
			mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
			if (key == 46 && env->map_on == 1)
				env->map_on = 0;
			else if (key == 46 && env->map_on == 0)
				env->map_on = 1;
			if (env->map_on == 1)
				mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
		}
	}
	return (0);
}

static int	motion_notify(int x, int y, t_env *env)
{
	if (env->menu == 1)
		return (0);
	if (x > 1200 || x < 0 || y > 870 || y < 0)
		return (0);
	if (x > 650)
		env->d_regard -= 1;
	else if (x < 550)
		env->d_regard += 1;
	if (y < 250 && (env->h_regard < (870 / 2 + 200)))
		env->h_regard += 2;
	else if (y > 620 && (env->h_regard > (870 / 2 - 200)))
		env->h_regard -= 2;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	clean_img(env);
	affichage_mur(env);
	color_case(env);
	quadrillage(env);
	print_cercle(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->map_on == 1)
		mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
	return (0);
}

static int	red_cross(int key)
{
	(void)key;
	exit(0);
	return (0);
}

static int 	win_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (-1);
	env->win = mlx_new_window(env->mlx, 1200, 870, "Wolf3D");
	env->imgmenu = mlx_new_image(env->mlx, 1200, 870);
	env->img = mlx_new_image(env->mlx, 1200, 870);
	env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->end);
	env->img2 = mlx_new_image(env->mlx, 200, 200);
	env->img_str2 = mlx_get_data_addr(env->img2, &env->bpp2, &env->s_l2, &env->end2);
	return (0);
}

int			main(int ac, char **av)
{
	t_env		env;

	if (win_init(&env) == -1)
		return (0);	

	env.menu = 0;
	if (pars_init(ac, av, &env) == 0)
	{
		env.coef = 400 / (env.x + env.y);
		init_env(&env);
		color_case(&env);
		quadrillage(&env);
		print_cercle(&env);
		affichage_mur(&env);
		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		mlx_put_image_to_window(env.mlx, env.win, env.img2, 960, 20);
	}

	env.menu = 1;
	open_menu(&env);

	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_hook(env.win, 2, 3, deal_key, &env);
	mlx_hook(env.win, 17, 3, red_cross, &env);
	mlx_loop(env.mlx);
	return (0);
}