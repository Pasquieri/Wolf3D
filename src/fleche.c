#include "../include/wolf3d.h"

void	fleche(t_env *env)
{
	t_perso	perso;

	env->rot_x = 10;
	env->rot_y = 10;
	env->rot_fleche = 225; // rotation a enlever de cette fonction
	rotation(env);

	perso.a.x = 100; // centre fleche(x,y)
	perso.a.y = 100;

/*	perso.b.x = perso.a.x - env->rot_x + env->rot.b.x;
	perso.b.y = perso.a.y + env->rot_y + env->rot.b.y; //

	perso.c.x = perso.a.x + env->rot.c.x; //
	perso.c.y = perso.a.y - env->rot_y + env->rot.c.y; //

	perso.d.x = perso.a.x + env->rot_x + env->rot.d.x; //
	perso.d.y = perso.a.y + env->rot_y + env->rot.d.y;*/

	perso.b.x = perso.a.x + env->rot.b.x; //-x
	perso.b.y = perso.a.y + env->rot.b.y; // +y

	perso.c.x = perso.a.x + env->rot.c.x; //
	perso.c.y = perso.a.y + env->rot.c.y; // -y

	perso.d.x = perso.a.x + env->rot.d.x; // +x
	perso.d.y = perso.a.y + env->rot.d.y; // +y
	ft_trace_seg(env, perso.a, perso.b);
	ft_trace_seg(env, perso.b, perso.c);
	ft_trace_seg(env, perso.c, perso.d);
	ft_trace_seg(env, perso.d, perso.a);

}
