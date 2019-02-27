#include "../include/wolf3d.h"

int		check_open_map(char *map, int fd, t_env *env)
{
	if (!(fd = open(map, O_RDONLY)))
		return (error_message(2, env));
	if (fd == -1)
		return (error_message(2, env));
	return (fd);
}