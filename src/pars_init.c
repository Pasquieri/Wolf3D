#include "../include/wolf3d.h"

int		pars_init(int argc, char **argv, t_env *env)
{
	int		fd;

	fd = -1;
	env->detail = 0;
	if (argc != 2)
	{
		if (argc == 3)
		{
			if (ft_atoi(argv[2]) > 0)
				env->detail = 1;
		}
		else
			return (error_message(1, env));
	}
	fd = check_open_map(argv[1], fd, env);
	if (fd == -1)
		return (-1);
	if (check_file(fd, env) == -1)
		return (-1);
	return (0);
}

// si on souhaite avoir le detail de l'erreur il faut ajouter un 3eme argument qui est une valeur supperieur a zero
// ex : ./Wolf3D map.x 1
