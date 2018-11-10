#include "../include/wolf3d.h"

static void	malloc_tab(t_env *env)
{
	int	i;

	i = 0;
	if (!(env->tab = (int **)malloc(sizeof(int *) * env->y)))
		exit(0);
	while (i < env->x)
	{
		if (!(env->tab[i] = (int *)malloc(sizeof(int) * env->x)))
			exit(0);
		i++;
	}
}

static void	fill_tab(int fd, t_env *env)
{
	char	*line;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[j])
		{
			env->tab[i][j] = ft_atoi(tmp[j]);
			free(tmp[j]);
			j++;
		}
		i++;
	}
	free(line);
}

void	open_map(char *map, t_env *env)
{
	int		fd;
	char	*line1;
	int		i;

	(void)env;
	line1 = NULL;
	if (!(fd = open(map, O_RDONLY)))
		exit (0);
	get_next_line(fd, &line1);
	env->x = ft_atoi(line1);
	i = 0;
	while (line1[i] != ',')
	{
		line1[i] = ' ';
		i++;
	}
	line1[i] = ' ';
	env->y = ft_atoi(line1);
	free(line1);
	malloc_tab(env);
	fill_tab(fd, env);
}

/*int	main(int argc,char **argv)
{
	t_env env;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (argc != 2)
		return (0);
	open_map(argv[1], &env);
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf("%d   ", env.tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}*/
