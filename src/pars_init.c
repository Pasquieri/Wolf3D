#include "../include/wolf3d.h"

static int	error_message(int num)
{
	ft_putstr("Erreur : ");
	if (num == 1)
		ft_putstr("Un parametre est attendu");
	else if (num == 2)
		ft_putstr("Ouverture de la map impossible");
	else if (num == 3)
		ft_putstr("Le malloc a merder");
	else if (num == 4)
		ft_putstr("Le nombre de collones (y) indiquer sont incorrect");
	else if (num == 5)
		ft_putstr("Le nombre de lignes (x) indiquer sont incorrect");
	else if (num == 6)
		ft_putstr("La premiere ligne de la map n'est pas sous la forme XX;");
	else if (num == 7)
		ft_putstr("Un des characteres de la map est incompatible");
	else if (num == 8)
		ft_putstr("Le nombre de caracteres n'est pas le meme pour toutes les lignes");
	else if (num == 9)
		ft_putstr("Le nombre de x et de y indique est trop elevee (10000 max)");
	else if (num == 10)
		ft_putstr("Le nombre indiauer est egal a zero ou n'existe pas");
	else if (num == 11)
		ft_putstr("La map n'a pas de case vide");
	else if (num == 12)
		ft_putstr("La map n'est pas cadre par des murs");
	else if (num == 13)
		ft_putstr("La map est vide");
	else if (num == 14)
		ft_putstr("Les coordonnee du player ne sont pas valide");
	else if (num == 15)
		ft_putstr("Le joueurs est pose dans un mur");
	ft_putchar('\n');
	return (-1);
}

static int	verif_char(char *str)
{
	int x;
	char nombre[3];

	nombre[2] = '\0';
	x = 0;
	while (str[x])
	{
		if (str[x + 1] != '\0')
		{
			nombre[0] = str[x];
			nombre[1] = str[x + 1];
			if (str[x] != ' ' && str[x + 1] != ' ')
				return (error_message(7));
		}
		if ((str[x] != '\0') && (str[x] != ' ') && ((str[x] >= 48)
					&& (str[x] <= 39) && (str[x] != '\n') 
					&& (str[x] != '\t')))
			return (error_message(7));
		x++;
	}
	return (x);
}

static int	compte_char(char *str, char c)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		x++;
		i++;
	}
	return (x);
}

static int	wall_row(char *str, int nb_char)
{
	if (str[0] == '0' && str[--nb_char] == '0')
		return (0);
	return (error_message(12));
}

static int	wall_line(char *str)
{
	int		i;
	char	c;

	c = '0';
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\n' && str[i] != ' ')
			return (error_message(12));
		i++;
	}
	return (0);
}

static int	tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		i--;
	return (i);
}

static int	fill_tab(int fd, t_env *env)
{
	char	*line;
	char	**tmp;
	int		nb_char;
	int		verif;
	int		i;
	int		j;
	int		nb_sol;

	nb_sol = 0;
	i = 0;
	line = NULL;
	nb_char = -1;
	while (get_next_line(fd, &line) == 1)
	{
		nb_char = ft_strlen(line);
		if (nb_char == 0)
			return (error_message(13));
		if (nb_char != (env->x * 3 - 2))
			return (error_message(5));
		verif = verif_char(line);
		if (verif == -1)
			return (-1);
		if (nb_char != verif)
			return (error_message(8));
		if (i == env->perso_y)
		{
			tmp = ft_strsplit(line, ' ');
			if (tablen(tmp) < env->perso_x)
				return (error_message(14));
			if (tmp[env->perso_x][0] == '0')
				return (error_message(15));
			free(tmp);
		}
			nb_sol += compte_char(line, '0');
		if (wall_row(line, nb_char) == -1)
			return (-1);
		if (i == 0)
			if (wall_line(line) == -1)
				return (-1);

		j = 0;
		tmp = ft_strsplit(line, ' ');
		while (j < env->x && tmp[j])
		{
			env->tab[i][j] = ft_atoi(tmp[j]);
			free(tmp[j]);
			j++;
		}
		
		i++;
		if (i == env->y)
			if (wall_line(line) == -1)
				return (-1);
	}
	if (env->perso_y >= i)
		return (error_message(14));
	if (i != env->y)
		return (error_message(4));
	if (nb_sol == 0)
		return (error_message(11));
	free(line);
	return (0);
}

static int	malloc_tab(t_env *env)
{
	int i;

	i = 0;
	if (!(env->tab = (int **)malloc(sizeof(int *) * env->y)))
		return (error_message(3));
	while (i < env->x)
	{
		if (!(env->tab[i] = (int *)malloc(sizeof(int) * env->x)))
			return (error_message(3));
		i++;
	}
	return (0);
}

static int	verif_valeur(char *str)
{
	int		valeur;

	valeur = ft_atoi(str);
	if (valeur == 0)
		return (error_message(10));
	if (valeur > 10000)
		return (error_message(9));
	return (valeur);
}

static int	recup_info_player(char *str, char c)
{
	int		i;
	int		x;
	int		y;

	if (c == 'x')
	{
		i = 0;
		while(str[i] != '(')
		{
			if (str[i] == '\0')
				return (-1);
			str[i] = ' ';
			i++;
		}
		str[i] = ' ';
		x = ft_atoi(str);
		while (str[i] != ',')
		{
			if (str[i] == '\0')
				return (-1);
			str[i] = ' ';
			i++;
		}
		str[i] = ' ';
		if (x > 0)
			return (x);
		else
			return (-1);
	}
	else if (c == 'y')
	{
		y = ft_atoi(str);
		if (y > 0)
			return (y);
		else
			return (-1);
	}
	return (-1);
}

static int	check_file(int	fd, t_env *env)
{
	char	*line1;
	//t_env	env;

	line1 = NULL;
	if (get_next_line(fd, &line1) != 1)
		return (error_message(13));
	env->perso_x = recup_info_player(line1, 'x');
	env->perso_y = recup_info_player(line1, 'y');
	if (env->perso_x != -1 && env->perso_y != -1)
	{
		if (get_next_line(fd, &line1) != 1)
			return (error_message(13));
	}
	else
		return (error_message(14));
	if (verif_valeur(line1) == -1) //faire la meme chose sur le vrai init
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

static int	check_open_map(char *map, int fd)
{
	if (!(fd = open(map, O_RDONLY)))
		return (error_message(2));
	if (fd == -1)
		return (error_message(2));
	return (fd);
}

int		pars_init(int argc, char **argv, t_env *env)
{
	int		fd;

	fd = -1;
	if (argc != 2)
		return (error_message(1));
	fd = check_open_map(argv[1], fd);
	if (fd == -1)
		return (-1);
	if (check_file(fd, env) == -1)
		return (-1);
	return (0);
}

// il faut modifier open map pour la premiere lignes
// et puis ajouter parse init dans le main et le makefile et dans l'include
