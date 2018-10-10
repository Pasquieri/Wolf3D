#include "../include/wolf3d.h"

static void	create_img(t_env *env)
{
	env->img = mlx_new_image(env->mlx, 1500, 1100);
	env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->end);
	mlx_destroy_image(env->mlx, env->img);
}

int			main(int ac, char **av)
{
	t_env	env;
	t_coord coord1;
	t_coord coord2;

	(void)ac;
	(void)av;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1500, 1100, "Wolf3D");
	create_img(&env);
	coord1.x = 10;
	coord1.y = 20;
	coord2.x = 400;
	coord2.y = 410;
	ft_trace_seg(&env, coord1, coord2);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
//	mlx_hook(env.win, 2, 3, deal_key, &env);
//	mlx_hook(env.win, 4, 1L << 2, button_press, &env);
//	mlx_hook(env.win, 17, 3, red_cross, &env);
//	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_loop(env.mlx);
	return (0);
}
