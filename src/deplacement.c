#include "../include/wolf3d.h"

static void	modif_env(int i, int j, t_env *env)
{
	int	key;

	key = env->key_tab[j][i];
	if (key == 123)
		env->perso_x--;
	else if (key == 124)
		env->perso_x++;
	else if (key == 125)
		env->perso_y++;
	else if (key == 126)
		env->perso_y--;
}

void	deplacements(int key, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (key == 123)
		i = 0;
	else if (key == 126)
		i = 1;
	else if (key == 125)
		i = 2;
	else if (key == 124)
		i = 3;
	if (env->d_regard >= 45 && env->d_regard < 135)
		j = 0;
	else if (env->d_regard >= 135 && env->d_regard < 225)
		j = 1;
	else if (env->d_regard >= 225 && env->d_regard < 315)
		j = 2;
	else
		j = 3;
//	printf("i = %d, j = %d, env->d_regard = %d\ntab_val = %d\n\n",i, j, env->d_regard,env->key_tab[j][i]);
	modif_env(i, j, env);
}
