/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:35:47 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/22 18:52:43 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_table(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i] != '\0')
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
