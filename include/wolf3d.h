#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct	s_cercle
{
	int	rayon;
	int	color;
	t_coord	coord;
}				t_cercle;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img; // image1
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;

	void	*img2; // image2
	char	*img_str2;
	int		bpp2;
	int		s_l2;
	int		end2;
	int		coef;

	int		x; // open_map
	int		y;
	int		**tab;

	int		hauteur_mur; // raycasting
	int		hauteur_cam;
	int		angle_cam;
	int		champs_visu;
	int		pos_x_cam;
	int		pos_y_cam;
	int		screen_x;
	int		screen_y;
	int		centre_ecran_x;
	int		centre_ecran_y;
	int		d_cam_ecran;
	int		angle_ray_cons;
}				t_env;

void	open_map(char *map, t_env *env);
void	init_env(t_env *env);
int		ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void	quadrillage(t_env *env);
void	put_pxl_img(t_env *env, int x, int y, int color);
void	color_case(t_env *env);
void	color_white(t_env *env);

void	cercle(t_env *env, t_cercle param);
int		adn(int xi, int yi, int xf, int yf, t_env *env);

#endif
