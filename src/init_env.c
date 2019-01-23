#include "../include/wolf3d.h"

void	init_env(t_env *env)
{
/************** Clara *************/
	env->d_regard = 270;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	//env->perso_x = 100;
	//env->perso_y = 100;
	env->perso_x = (env->perso_x + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->perso_y + 1) * env->coef - env->coef / 2;
	// 5 & 3 sont les cases dans laquelle on place le perso des le depart
	env->nb_colonne = 200;
}
