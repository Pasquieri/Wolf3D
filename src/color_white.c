#include "../include/wolf3d.h"

void	color_white(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (1200 * 870))
	{
		env->img_str[j] = (char)255;
		env->img_str[j + 1] = (char)255;
		env->img_str[j + 2] = (char)255;
		j = j+4;
		i++;
	}
}
