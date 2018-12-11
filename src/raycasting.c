#include "../include/wolf3d.h"

static void	affiche_mur(int b, int a, float x, float y)
{
	printf("il y a un mur : a = %d, b = %d, x = %f, y = %f\n", a,b, x, y);

}

void	raycasting(t_env *env)
{
	int			i;
	float		angle; // limite angle gauche
	float		x;
	float		y;
	int			a;
	int			b;

	i = 0;
	if ((angle = env->d_regard + 30) > 360) // si d_regard = 350 : 350 + 30 = 380 or == 20 sur le cercle trigonometrique
		angle = env->d_regard + 30 - 360;
	printf("angle : %f\n ", angle);
	while (i < env->nb_colonne)
	{
		x = env->perso_x;
		y = env->perso_y;
		a = (int)x / env->coef - 1;
		b = (int)y / env->coef;
		while (env->tab[b][a] != 0) // tab == 0 ?  == mur ?
		{
			x += cos(angle * M_PI / 180);
			y += sin(angle * M_PI / 180);
			a = (int)x / env->coef - 1; // decalage du quadrillage, ca commence pas direct a 0 mais a env->coef : x/coef => ex : 40/15 = 2 --> case 2 dans le tableau de la map
			b = (int)y / env->coef; // contrairement aux y : cf avec color white on voit direct la diff
			//if (env->tab[b][a] == 0)
		}
		if (env->tab[b][a] == 0)
		{
			affiche_mur(b,a, x, y);
		}
		if ((angle -= 60. / env->nb_colonne) < 0.)
			angle += 360.; // inverse du cas plus haut : boucle autour de 360 deg.
		i++;
	}
}
