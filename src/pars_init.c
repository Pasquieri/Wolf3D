#include "../include/wolf3d.h"

static int	error_message(int num, t_env *env) //Cette fonction affiche les messages d'erreurs et retourn (-1) pour arreter le programme
{
	ft_putstr("Erreur : ");
	if (env->detail > 0)
	{
		if (num == 1)
			ft_putstr("Un parametre est attendu");
		else if (num == 2)
			ft_putstr("Ouverture de la map impossible");
		else if (num == 3)
			ft_putstr("Erreur de malloc");
		else if (num == 4)
			ft_putstr("Le nombre de colonnes (y) indique est incorrect");
		else if (num == 5)
			ft_putstr("Le nombre de lignes (x) indique est incorrect");
		else if (num == 6)
			ft_putstr("La premiere ligne de la map doit etre \"player : (X,X);\"");
		else if (num == 7)
			ft_putstr("Un des caracteres de la map est incompatible");
		else if (num == 8)
			ft_putstr("Le nombre de caracteres n'est pas le meme pour toutes les lignes");
		else if (num == 9)
			ft_putstr("Le nombre de x et de y indique est trop elevee (10000 max)");
		else if (num == 10)
			ft_putstr("Le nombre indique est egal a zero ou n'existe pas");
		else if (num == 11)
			ft_putstr("La map n'a pas de case vide");
		else if (num == 12)
			ft_putstr("La map n'est pas cadre par des murs");
		else if (num == 13)
			ft_putstr("La map est vide");
		else if (num == 14)
			ft_putstr("Les coordonnees du player ne sont pas valides");
		else if (num == 15)
			ft_putstr("Le joueur est place dans un mur");
	}
	else if (env->detail == 0)
		ft_putstr("map invalide");
	ft_putchar('\n');
	return (-1);
}

static int	verif_char(char *str, t_env *env) //verif que *str cest bien composer de char valides
{
	int		x;
	char	nombre[3];

	nombre[2] = '\0';
	x = 0;
	while (str[x])
	{
		if (str[x + 1] != '\0')
		{
			nombre[0] = str[x];
			nombre[1] = str[x + 1];
			if (str[x] != ' ' && str[x + 1] != ' ')
				return (error_message(7, env));
		}
		if ((str[x] != '\0') && (str[x] != ' ') && ((str[x] >= 48)
					&& (str[x] <= 39) && (str[x] != '\n')
					&& (str[x] != '\t')))
			return (error_message(7, env));
		x++;
	}
	return (x);
}

static int	compte_char(char *str, char c) // cette fonction compte le nombre de char de la map a charger dans un tab
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

static int	wall_row(char *str, int nb_char, t_env *env) // verifie que les premiers et dernier char sont ne sont pas des cases vides
{
	if (str[0] == '0' && str[--nb_char] == '0')
		return (0);
	return (error_message(12, env));
}

static int	wall_line(char *str, t_env *env) // verifie que les premiers et dernier char sont ne sont pas des cases vides
{
	int		i;
	char	c;

	c = '0';
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\n' && str[i] != ' ')
			return (error_message(12, env));
		i++;
	}
	return (0);
}

static int	tablen(char **str) //
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

static int	malloc_tab(t_env *env)
{
	int i;

	i = 0;
	if (!(env->tab = (int **)malloc(sizeof(int *) * env->y)))
		return (error_message(3, env));
	while (i < env->x)
	{
		if (!(env->tab[i] = (int *)malloc(sizeof(int) * env->x)))
			return (error_message(3, env));
		i++;
	}
	return (0);
}

static int	verif_valeur(char *str, t_env *env)
{
	int		valeur;

	valeur = ft_atoi(str);
	if (valeur == 0)
		return (error_message(10, env));
	if (valeur > 10000)
		return (error_message(9, env));
	return (valeur);
}

static int	recup_info_player(char *str, char c) // recup et verif les info des coordonee du player mis dans la fichier .map
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

static int	check_open_map(char *map, int fd, t_env *env)
{
	if (!(fd = open(map, O_RDONLY)))
		return (error_message(2, env));
	if (fd == -1)
		return (error_message(2, env));
	return (fd);
}

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
