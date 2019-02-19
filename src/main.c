#include "../include/wolf3d.h"

static int	deal_key(int key, t_env *env) // 37 lignes
{
	t_cercle	param_cercle;

	if (key == 53)
		exit(0);
	if (key == 69 ||key == 27 || key == 24 || key == 78 || (key >= 123 && key <= 126) || key == 46)
	{
		if (key == 69 || key == 27)
			env->d_regard+= 5;
		else if (key == 78 || key == 24)
			env->d_regard-= 5;
		env->d_regard = env->d_regard % 360;
		if (env->d_regard < 0)
			env->d_regard = env->d_regard + 360;
		if (key >= 123 && key <= 126)
			deplacements(key, env);
		clean_img(env);
		color_case(env);
		quadrillage(env);
		param_cercle.coord.x = env->perso_x;
		param_cercle.coord.y = env->perso_y;
		param_cercle.rayon = 5;
		param_cercle.color = 3;
		while (param_cercle.rayon >= 0) // petit cercle : perso
		{
			cercle(env, param_cercle);
			param_cercle.rayon--;
		}
		affichage_mur(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		if (key == 46 && env->map_on == 1)
			env->map_on = 0;
		else if (key == 46 && env->map_on == 0)
			env->map_on = 1;
		if (env->map_on == 1)
			mlx_put_image_to_window(env->mlx, env->win, env->img2, 960, 20);
	}
	return (0);
}

static int	red_cross(int key)
{
	(void)key;
	exit(0);
	return (0);
}

int			main(int ac, char **av) // 31 - 33 lignes
{
	t_env		env;
	t_cercle	param_cercle;

	if (pars_init(ac, av, &env) == -1)
		return (0);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1200, 870, "Wolf3D");
	env.img = mlx_new_image(env.mlx, 1200, 870);
	/******* img 1 avec le labyrinthe *********/
	env.img_str = mlx_get_data_addr(env.img, &env.bpp, &env.s_l, &env.end);
	/* ================================================================== */
                         // Mini Map //
	env.img2 = mlx_new_image(env.mlx, 200, 200);
	/******* img 2 mini map en haut a droite *********/
	env.img_str2 = mlx_get_data_addr(env.img2, &env.bpp2, &env.s_l2, &env.end2);
	env.coef = 400 / (env.x + env.y);
	init_env(&env);
	color_case(&env);
	quadrillage(&env);

	param_cercle.coord.x = env.perso_x;
	param_cercle.coord.y = env.perso_y;
	param_cercle.rayon = 5;
	param_cercle.color = 3;
	while (param_cercle.rayon >= 0) // petit cercle : perso
	{
		cercle(&env, param_cercle);
		param_cercle.rayon--;
	}
	affichage_mur(&env);
	/* ================================================================== */
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_put_image_to_window(env.mlx, env.win, env.img2, 960, 20); //1000,20

	mlx_hook(env.win, 2, 3, deal_key, &env);
	//	mlx_hook(env.win, 4, 1L << 2, button_press, &env);
	mlx_hook(env.win, 17, 3, red_cross, &env);
	//	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_loop(env.mlx);
	return (0);
}
