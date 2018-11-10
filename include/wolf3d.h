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

typedef struct	s_env
{
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

	int		x;
	int		y;
	int		**tab;
}				t_env;

void	put_pxl_img(t_env *env, int x, int y, int color);
int		ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void	quadrillage(t_env *env);
void	color_case(t_env *env);
void	open_map(char *map, t_env *env);

#endif
