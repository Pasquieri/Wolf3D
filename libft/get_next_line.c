/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:04:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/26 16:54:17 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	gnl_reader(t_gnlstore *store, int fd)
{
	if (store->cache[fd] == NULL)
		store->cache[fd] = ft_strnew(1);
	while (!(ft_strchr(store->cache[fd], '\n')) &&
		(store->read_bytes = read(fd, store->buff, BUFF_SIZE)) > 0)
	{
		store->buff[store->read_bytes] = '\0';
		store->tmp = store->cache[fd];
		store->cache[fd] = ft_strjoin(store->cache[fd], store->buff);
		ft_strdel(&store->tmp);
	}
	ft_strdel(&store->buff);
}

int			get_next_line(int const fd, char **line)
{
	static t_gnlstore	store;

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFF_SIZE <= 0
			|| (BUFF_SIZE) > (MAX_INT)
			|| !(store.buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	gnl_reader(&store, fd);
	if (store.read_bytes == -1)
		return (-1);
	*line = ft_strsub(store.cache[fd], 0, ft_strlenre(store.cache[fd], '\n'));
	if (ft_strchr(store.cache[fd], '\n'))
	{
		store.tmp = store.cache[fd];
		store.cache[fd] = ft_strdup(ft_strchr(store.cache[fd], '\n') + 1);
		ft_strdel(&store.tmp);
		return (1);
	}
	if (ft_strlenre(store.cache[fd], '\n') > 0)
	{
		store.cache[fd] = store.cache[fd] + ft_strlenre(store.cache[fd], '\n');
		return (1);
	}
	return (0);
}

/*int	 main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (0);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	free(line);
	line = NULL;
	while (1) {};
	return (0);
}*/
