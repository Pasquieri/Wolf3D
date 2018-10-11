#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct	s_map
{
	int		x;
	int		y;
	char	*map;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;
	int		x;
	int		y;
	int		coef;
	int		map;
}				t_env;

void	put_pxl_img(t_env *env, float x, float y, int color);
int		ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);
void	quadrillage(t_env *env);
void	init_map(t_map *map);
void	init_env(t_env *env, t_map *map);
void	color_case(t_env *env, t_map map);

#endif
