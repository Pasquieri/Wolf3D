#include "../include/wolf3d.h"

void	rotation(t_env *env)
{
	float	rot;
	float	x;
	float	y;

	x= 10;
	y = 10;
	if (env->rot_fleche == 0)
	{
		env->rot.b.x = 0-x;
		env->rot.b.y = 0+y;
		env->rot.c.x = 0;
		env->rot.c.y = 0-y;
		env->rot.d.x = 0+x;
		env->rot.d.y = 0+y;
	}
	else if (env->rot_fleche <= 90)
	{
		rot = 90 / env->rot_fleche;
		env->rot.b.x = 0 - x;
		env->rot.b.y = - 2 * env->rot_y / rot +y;
		env->rot.c.x = env->rot_x / rot;
		env->rot.c.y = env->rot_y /rot -y;
		env->rot.d.x = - 2 * env->rot_x/rot +x;
		env->rot.d.y = 0 +y;
	}
	else if (env->rot_fleche <= 180)
	{
		rot = 180 / env->rot_fleche;
		env->rot.b.x = 2 * env->rot_x / rot - x;
		env->rot.b.y = 0 - y;
		env->rot.c.x = - env->rot_x / rot + x;
		env->rot.c.y = env->rot_y / rot;
		env->rot.d.x = 0 - x;
		env->rot.d.y = - 2 * env->rot_y /rot + y;
	}
	else if (env->rot_fleche <= 270)
	{
		rot = 270 / env->rot_fleche;
	/*	env->rot.b.x = x;
		env->rot.b.y = - y;
		env->rot.c.x = 0;
		env->rot.c.y = y;
		env->rot.d.x = -x;
		env->rot.d.y = -y;*/
		env->rot.b.x = x;
		env->rot.b.y = 2 * env->rot_y / rot - y;
		env->rot.c.x = - env->rot_x / rot ;
		env->rot.c.y = - env->rot_y / rot + y;
		env->rot.d.x = - 2 * env->rot_x / rot - x;
		env->rot.d.y = -  y;
	}
	else if (env->rot_fleche <= 360)
	{
		rot = 360 / env->rot_fleche;
		env->rot.b.x = 0;
		env->rot.b.y = - 2 * env->rot_y / rot;
		env->rot.c.x = env->rot_x / rot;
		env->rot.c.y = env->rot_y /rot;
		env->rot.d.x = - 2 * env->rot_x/rot ;
		env->rot.d.y = 0;
	}
}
