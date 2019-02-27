#include "../include/wolf3d.h"

int		check_file(int	fd, t_env *env)
{
	char	*line1;

	line1 = NULL;
	if (get_next_line(fd, &line1) != 1)
		return (error_message(13, env));
	env->perso_x = recup_info_player(line1, 'x');
	env->perso_y = recup_info_player(line1, 'y');
	if (env->perso_x != -1 && env->perso_y != -1)
	{
		free(line1);
		if (get_next_line(fd, &line1) != 1)
			return (error_message(13, env));
	}
	else
		return (error_message(14, env));
	if (verif_valeur(line1, env) == -1) //faire la meme chose sur le vrai init
		return (-1);
	env->x = ft_atoi(line1); //on recupere le x ecrit dans la map
	env->y = ft_atoi(line1); //on recupere le y ecrit dans la map
	free(line1);
	if (malloc_tab(env) == -1)
		return (-1);
	if (fill_tab(fd, env) == -1)
		return (-1);
	return (0);
}