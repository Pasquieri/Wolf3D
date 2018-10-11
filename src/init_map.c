#include "../include/wolf3d.h"

void	init_map(t_map *map)
{
	map->x = 10;
	map->y = 10;
	if (!(map->map = (char *)malloc(sizeof(char) * (map->x * map->y + 1))))
		exit(0);
	map->map = "1111111111011111111000111111000001111000000011000000001100000001111000001111110001111111101111111111\0";
}
