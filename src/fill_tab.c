#include "../include/wolf3d.h"

int		fill_tab(int fd, t_env *env)
{
	char	*line;
	char	**tmp;
	int		nb_char;
	int		verif;
	int		i;
	int		j;
	int		nb_sol;
	int		k;

	nb_sol = 0;
	i = 0;
	line = NULL;
	nb_char = -1;
	while (get_next_line(fd, &line) == 1)
	{
		nb_char = ft_strlen(line);
		if (nb_char == 0)
			return (error_message(13, env));
		if (nb_char != (env->x * 3 - 2))
			return (error_message(5, env));
		verif = verif_char(line, env);
		if (verif == -1)
			return (-1);
		if (nb_char != verif)
			return (error_message(8, env));
		if (i == env->perso_y)
		{
			tmp = ft_strsplit(line, ' ');
			if (tablen(tmp) < env->perso_x)
				return (error_message(14, env));
			if (tmp[env->perso_x][0] == '0')
				return (error_message(15, env));
			k = tablen(tmp);
			while (k >= 0)
			{
				free(tmp[k]);
				k--;
			}
			free(tmp);
		}
			nb_sol += compte_char(line, '0');
		if (wall_row(line, nb_char, env) == -1)
			return (-1);
		if (i == 0)
			if (wall_line(line, env) == -1)
				return (-1);

		j = 0;
		tmp = ft_strsplit(line, ' ');
		while (j < env->x && tmp[j])
		{
			env->tab[i][j] = ft_atoi(tmp[j]);
			free(tmp[j]);
			j++;
		}
		free(tmp);
		i++;
		if (i == env->y)
			if (wall_line(line, env) == -1)
				return (-1);
		free(line);
		line = NULL;
	}
	if (env->perso_y >= i)
		return (error_message(14, env));
	if (i != env->y)
		return (error_message(4, env));
	if (nb_sol == 0)
		return (error_message(11, env));
	free(line);
	return (0);
}
