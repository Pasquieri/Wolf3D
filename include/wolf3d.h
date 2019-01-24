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
	int		map_on;

	int		x; // open_map
	int		y;
	int		**tab;

	int	d_regard; //clara
	double	angle;
	int		perso_x;
	int		perso_y;
	int		nb_colonne;
	int		d_ecran;
	int		h_mur;
	int		h_regard;
}				t_env;

int		pars_init(int argc, char **argv, t_env *var_check);
void	open_map(char *map, t_env *env);
void	init_env(t_env *env);
int		ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void	quadrillage(t_env *env);
void	put_pxl_img(t_env *env, int x, int y, int color);
void	clean_img(t_env *env);
void	color_case(t_env *env);
void	color_white(t_env *env);
void	cercle(t_env *env, t_cercle param);
double	detection_mur(t_env *env);
void	init_var_hor(t_env *env, double *ya, double *xa, t_coord *coord1);
int		coef_hor(t_env *env, int *coef_x, int *coef_y);
int		verif_hor(t_env *env, t_coord *coord);
void	init_var_ver(t_env *env, double *ya, double *xa, t_coord *coord2);
int		coef_ver(t_env *env, int *coef_x, int *coef_y);
int		verif_ver(t_env *env, t_coord *coord);
t_coord	intersection_horizontal(t_env *env);
t_coord	intersection_vertical(t_env *env);
void	affichage_mur(t_env *env);
#endif
