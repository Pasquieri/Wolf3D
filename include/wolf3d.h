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

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;
}				t_env;

void	put_pxl_img(t_env *env, float x, float y);
int		ft_trace_seg(t_env *env, t_coord coord1, t_coord coord2);

#endif
