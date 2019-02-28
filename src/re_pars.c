#include "../include/wolf3d.h"

int		re_pars(char *str, t_env *env)
{
	int		fd;

	env->map_entree = -1;
	fd = -1;
	env->detail = 0;

	fd = check_open_map(str, fd, env);
	if (fd == -1)
		return (-1);
	if (check_file(fd, env) == -1)
		return (-1);
	env->map_entree = 0;
	return (0);
}