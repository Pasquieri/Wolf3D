#include "../include/wolf3d.h"

void	fleche(t_env *env)
{
	t_perso	perso;

	env->rot_fleche = M_PI/2; // rotation a enlever de cette fonction
	perso.a.x = 100; // centre fleche(x,y)
	perso.a.y = 100;

/*	perso.v_i.x = (perso.a.x + 10) * cos(env->rot_fleche) - (perso.a.y + 0)
		* sin(env->rot_fleche); // calcul x' = xcos(a) - ysin(a)
	perso.v_i.y = (perso.a.x + 10) * sin(env->rot_fleche) + (perso.a.y + 0)
		* cos(env->rot_fleche); // calcul y' = xsin(a) + ycos(a)
	perso.v_j.x = (perso.a.x + 0) * cos(env->rot_fleche) - (perso.a.y + 10)
		* sin(env->rot_fleche);
	perso.v_j.y = (perso.a.x + 0) * sin(env->rot_fleche) + (perso.a.y + 10)
		* cos(env->rot_fleche);*/

	perso.v_i.x = (20) * cos(env->rot_fleche) - (0) * sin(env->rot_fleche); // calcul x' = xcos(a) - ysin(a)
	perso.v_i.y = (20) * sin(env->rot_fleche) + (0) * cos(env->rot_fleche); // calcul y' = xsin(a) + ycos(a)
	perso.v_j.x = (0) * cos(env->rot_fleche) - (20) * sin(env->rot_fleche);
	perso.v_j.y = (0) * sin(env->rot_fleche) + (20) * cos(env->rot_fleche);
	printf(" v_i x : %f \n", perso.v_i.x);
	printf(" v_i y : %f \n", perso.v_i.y);
	printf(" v_j x : %f \n", perso.v_j.x);
	printf(" v_j y : %f \n", perso.v_j.y);
	printf(" cos(angle) : %f \n", cos(env->rot_fleche));
	perso.b.x = perso.a.x - perso.v_i.x - perso.v_j.x;
	perso.b.y = perso.a.y + perso.v_i.y + perso.v_j.y;

	perso.c.x = perso.b.x + perso.v_i.x + perso.v_j.x;
	perso.c.y = perso.b.y - 2 * (perso.v_i.y + perso.v_j.y);

	perso.d.x = perso.c.x + perso.v_i.x + perso.v_j.x;
	perso.d.y = perso.c.y + 2 * (perso.v_i.y + perso.v_j.y);

	ft_trace_seg(env, perso.a, perso.b);
	ft_trace_seg(env, perso.b, perso.c);
	ft_trace_seg(env, perso.c, perso.d);
	ft_trace_seg(env, perso.d, perso.a);

}
