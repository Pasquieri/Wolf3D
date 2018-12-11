#include "../include/wolf3d.h"

void	init_env(t_env *env)
{
/************** Clara *************/
	env->d_regard = 45;
	env->perso_x = 100; // == param_cercle.coord.x (main)
	env->perso_y = 100;
	env->champ_left = env->d_regard + 30;
	env->champ_right = env->d_regard - 30;
	env->nb_colonne = 200;

/************** ADN ***************/
	env->hauteur_mur = 64;
	env->hauteur_cam = env->hauteur_mur/2; // hauteur_mur / 2
	env->champs_visu = 60; // angle de vue 60*
	env->pos_x_cam = 160; // position (x,y) du perso/cam
	env->pos_y_cam = 100;
	env->screen_x = 320; // dimension (x,y) ecran projection
	env->screen_y = 200;
	env->d_cam_ecran = (env->screen_x / 2) / tan(((env->champs_visu / 2) * M_PI)/180); // = 277
	env->centre_ecran_x = 160;
	env->centre_ecran_y = 100;
	env->angle_ray_cons = (60/320);

	env->angle_cam = 45; // variable
}
