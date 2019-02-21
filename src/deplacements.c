/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:41:36 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/21 17:41:39 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	deplacements(int key, t_env *env)
{
	if (key == 125 || key == 126)
		depla_vertical(env, key);
	else if (key == 123 || key == 124)
		depla_horizontal(env, key);
}
