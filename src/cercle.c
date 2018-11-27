#include "../include/wolf3d.h"

static void	verif_mur(t_env *env, int x, int y, int color)
{
	int	i;

	i = 4 * x + y * env->s_l2;
	if (((env->img_str2[i] == (char)113) && (env->img_str2[i + 1] == (char)170) && (env->img_str2[i + 2] == (char)10)) || ((env->img_str2[i] == (char)200) && (env->img_str2[i + 1] == (char)220) && (env->img_str2[i + 2] == (char)254)))
		put_pxl_img(env, x, y, color);
}

void		cercle(t_env *env, t_cercle param)
{
	int x;
	int y;
	int m;

	x = 0;
	y = param.rayon;
	m = 5 - 4 * param.rayon;
	while (x <= y)
	{
	//	verif_mur(env, x+param.coord.x, -y+param.coord.y, param.color); //1
	//	verif_mur(env, y+param.coord.x, -x+param.coord.y, param.color); //2
	//	verif_mur(env, y+param.coord.x, x+param.coord.y, param.color); //3
	//	verif_mur(env, x+param.coord.x, y+param.coord.y, param.color); //4
		verif_mur(env, -x+param.coord.x, y+param.coord.y, param.color); //5
	//	verif_mur(env, -y+param.coord.x, x+param.coord.y, param.color); //6
	//	verif_mur(env, -y+param.coord.x, -x+param.coord.y, param.color); //7
	//	verif_mur(env, -x+param.coord.x, -y+param.coord.y, param.color); //8
		if (m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}
