/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:13:49 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/28 15:32:18 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}				t_coord;

typedef struct	s_cercle
{
	int		rayon;
	int		color;
	t_coord	coord;
}				t_cercle;

typedef struct	s_coef
{
	int		x;
	int		y;
}				t_coef;

typedef struct 	s_color_menu
{
	int 	blue_color;
 	int 	white_color;
	int 	green_color;

	int 	play_color;
	int 	exit_color;
	int 	map1_color;
	int 	map2_color;
	int 	map3_color;	
}				t_color_menu;

typedef struct	s_env
{
	void	*imgmenu;
//	char	*imgmenu_str;

	void	*mlx;
	void	*win;
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;

	void	*img2;
	char	*img_str2;
	int		bpp2;
	int		s_l2;
	int		end2;
	int		coef;
	int		map_on;

	int		x; //remplcer les y par x car meme valeur
	int		y;
	int		**tab;

	int		d_regard;
	double	angle;
	int		detail;
	int		x_init; // valeur initiale de perso_x et perso_y ==> cases
	int		y_init;
	int		perso_x; // modifier dans init env 
	int		perso_y;
	int		menu;
	int 	menu_select;
	int 	map_entree;
	int		nb_colonne;
	float	d_ecran;
	int		h_mur;
	int		h_regard;
	float	lim;
	int		orientation;
}				t_env;

int				re_pars(char *str, t_env *env);
int				check_open_map(char *map, int fd, t_env *env);
int				check_file(int	fd, t_env *env);
int				recup_info_player(char *str, char c);
int				verif_valeur(char *str, t_env *env);
int				malloc_tab(t_env *env);
int				fill_tab(int fd, t_env *env);
int				tablen(char **str);
int				wall_line(char *str, t_env *env);
int				wall_row(char *str, int nb_char, t_env *env);
int				compte_char(char *str, char c);
int				verif_char(char *str, t_env *env);
int 			error_message(int num, t_env *env);
void			open_menu(t_env *env);
int				pars_init(int argc, char **argv, t_env *var_check);
void			init_env(t_env *env);
int				ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void			quadrillage(t_env *env);
void			put_pxl_img(t_env *env, int x, int y, int color);
void			clean_img(t_env *env);
void			color_case(t_env *env);
void			color_white(t_env *env);
void			cercle(t_env *env, t_cercle param);
void			print_cercle(t_env *env);
double			detection_mur(t_env *env);
int				init_var_hor(t_env *env, double *ya, double *xa, t_coord *c1);
int				coef_hor(t_env *env, int *coef_x, int *coef_y);
int				verif_hor(t_env *env, t_coord *coord);
int				init_var_ver(t_env *env, double *ya, double *xa, t_coord *c2);
int				coef_ver(t_env *env, int *coef_x, int *coef_y);
int				verif_ver(t_env *env, t_coord *coord);
int				intersection_horizontal(t_env *env, t_coord *cd);
int				intersection_vertical(t_env *env, t_coord *cd);
void			affichage_mur(t_env *env);
void			deplacements(int key, t_env *env);
void			depla_horizontal(t_env *env, int key);
void			depla_vertical(t_env *env, int key);

#endif
