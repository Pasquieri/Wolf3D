#include "../include/wolf3d.h"

static int	deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	(void)env;
	return (0);
}

static int	red_cross(int key)
{
	(void)key;
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;
	t_map	map;

	(void)ac;
	(void)av;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1500, 1100, "Wolf3D");
	env.img = mlx_new_image(env.mlx, 1500, 1100);
	/******* img 1 avec le labyrinthe *********/
	env.img_str = mlx_get_data_addr(env.img, &env.bpp, &env.s_l, &env.end);
/* ================================================================== */
                          // Mini Map //
	env.img2 = mlx_new_image(env.mlx, 200, 200);
	env.img_str2 = mlx_get_data_addr(env.img2, &env.bpp2, &env.s_l2, &env.end2);
	/******* img 2 mini map en haut a droite *********/
	init_map(&map);
	/******* map de 1 et 0 a refaire avec ouverture d'un fichier *********/
	/******* voir open map *********/
	init_env(&env, &map);
	/******* en rapport avec map *******/
	color_case(&env, map);
	/******* color les cases de la mini map ********/
	quadrillage(&env);
	/******* quadrillage de la mini map ********/

	/* ================================================================== */
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	/******* img 1 avec le labyrinthe *********/
	mlx_put_image_to_window(env.mlx, env.win, env.img2, 1320, 20);
	/******* img 2 mini map en haut a droite *********/

	mlx_hook(env.win, 2, 3, deal_key, &env);
//	mlx_hook(env.win, 4, 1L << 2, button_press, &env);
	mlx_hook(env.win, 17, 3, red_cross, &env);
//	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_loop(env.mlx);
	return (0);
}
