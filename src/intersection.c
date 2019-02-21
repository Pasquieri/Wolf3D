/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:49:16 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/21 21:13:21 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	verif_horizontal(float y2, t_env *env)
{
	int	j;

	j = round(y2) / env->coef;
	if (j != (env->perso_y / env->coef))
		return (1);
	else
		return (0);
}

t_coord		intersection_horizontal(t_env *env)
{
	int		ya;
	int		coef_y;
	int		coef_x;
	t_coord	cd;

	ya = 0;
	cd.x = env->perso_x;
	cd.y = env->perso_y;
	coef_y = 1;
	coef_x = 1;
	if (env->angle > 0. && env->angle < 180.)
		coef_y = -1;
	if (env->angle > 180. && env->angle < 360.)
		coef_x = -1;
	while (ya < env->coef && (cd.x < env->lim_h && cd.x > 0.)
			&& (cd.y < env->lim_h && cd.y > 0.) && (env->tab[(int)round(cd.y)
				/ env->coef][(int)round(cd.x) / env->coef]) != 0)
	{
		cd.y = cd.y + coef_y;
		cd.x = env->perso_x + ((ya * coef_x) / tan(env->angle * M_PI / 180));
		if (verif_horizontal(cd.y, env) == 1)
			ya = env->coef;
		ya++;
	}
	return (cd);
}

static int	verif_vertical(float x2, t_env *env)
{
	int	i;

	i = round(x2) / env->coef;
	if (i != (env->perso_x / env->coef))
		return (1);
	else
		return (0);
}

t_coord		intersection_vertical(t_env *env)
{
	int		xa;
	int		coef_x;
	int		coef_y;
	t_coord	cd;

	xa = 0;
	cd.x = env->perso_x;
	cd.y = env->perso_y;
	coef_x = 1;
	coef_y = 1;
	if (env->angle > 90. && env->angle < 270.)
		coef_x = -1;
	if (!(env->angle > 90. && env->angle < 270.))
		coef_y = -1;
	while (xa < env->coef && (cd.x < env->lim_v && cd.x > 0.)
			&& (cd.y < env->lim_v && cd.y > 0.) && (env->tab[(int)round(cd.y)
				/ env->coef][(int)round(cd.x) / env->coef]) != 0)
	{
		cd.x = cd.x + coef_x;
		cd.y = env->perso_y + ((xa * coef_y) * tan(env->angle * M_PI / 180));
		if (verif_vertical(cd.x, env) == 1)
			xa = env->coef;
		xa++;
	}
	printf("x2, %f, y2 %f \n",cd.x, cd.y);
	return (cd);
}
