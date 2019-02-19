#include "../include/wolf3d.h"

void	init_env(t_env *env)
{
	env->d_regard = 0;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	env->perso_x = (env->perso_x + 1) * env->coef - env->coef / 2;
	env->perso_y = (env->perso_y + 1) * env->coef - env->coef / 2;
	// 5 & 3 sont les cases dans laquelle on place le perso des le depart
	env->nb_colonne = 1200;
	env->d_ecran = (env->nb_colonne / 2) / tan(30 * M_PI / 180);
	env->h_mur = env->coef;
	env->h_regard = 870 / 2; // nb_ligne / 2 ==> moitie de l'ecran
	env->map_on = 1;
}
