/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:36:28 by cpalmier          #+#    #+#             */
/*   Updated: 2018/01/31 18:24:25 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_next_line(char **next_line, char *buff)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1))))
		return ;
	while (buff[++i])
		tmp[j++] = buff[i];
	tmp[j] = '\0';
	if (*next_line)
		free(*next_line);
	*next_line = ft_strdup(tmp);
	free(tmp);
}

void	fill_line(char **line, char *buff)
{
	char	*tmp;
	size_t	len;

	if (*line)
	{
		tmp = ft_strjoin(*line, buff);
		free(*line);
	}
	else
		tmp = ft_strdup(buff);
	len = ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n'));
	*line = ft_strsub(tmp, 0, len);
	free(tmp);
}

int		check_next_line(char **next_line, char **line)
{
	if (*next_line && ft_strchr(*next_line, '\n'))
	{
		fill_line(line, *next_line);
		fill_next_line(next_line, *next_line);
		return (1);
	}
	if (*next_line && !ft_strchr(*next_line, '\n'))
	{
		fill_line(line, *next_line);
		*next_line = NULL;
		return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*next_line;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if ((ret = check_next_line(&next_line, line) == 1))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		fill_line(line, buff);
		if (ft_strchr(buff, '\n'))
		{
			fill_next_line(&next_line, buff);
			return (1);
		}
	}
	if (ret == 0 && ft_strlen(*line) > 0)
		return (1);
	return (0);
}
