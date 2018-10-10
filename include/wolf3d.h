#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_str;
	int		bpp;
	int		s_l;
	int		end;
}				t_env;

#endif
