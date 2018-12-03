#include "../include/wolf3d.h"

int	adn(int xi, int yi, int xf, int yf, t_env *env)
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	int		i;

	dx = xf - xi;
	dy = yf - yi;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / steps;
	yinc = dy / steps;
	x = xi;
	y = yi;
	put_pxl_img(env, round(x), round(y), 3); //
	i = 0;
	while (i < steps - 1)
	{
		x = x + xinc;
		y = y + yinc;
		put_pxl_img(env, round(x), round(y), 3);
		i++;
	}
	return (steps);
}
