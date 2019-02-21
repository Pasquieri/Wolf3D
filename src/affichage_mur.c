/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/21 21:12:38 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		affichage(double h_percue, t_env *env, int x)
{
	int	y;
	int	min;
	int	max;

	min = round(env->h_regard - (h_percue / 2));
	max = round(env->h_regard + (h_percue / 2));
	y = 0;
	while (y < 870)
	{
		if (y < min)
		{
			put_pxl_img(env, x, y, 6);
		}
		else if (y > max)
		{
			put_pxl_img(env, x, y, 7);
		}
		else
		{
			put_pxl_img(env, x, y, 5);
		}
		y++;
	}
}

static double	verif_angle(double angle)
{
	if (angle < 0.)
	{
		while (angle < 0.)
			angle = angle + 360.;
	}
	else if (angle > 360.)
	{
		while (angle > 360.)
			angle = angle - 360.;
	}
	if (angle == 360.)
		angle = 0.;
	return (angle);
}

void			affichage_mur(t_env *env)
{
	double	a;
	double	dist;
	double	h_percue;
	int		x;

	a = env->d_regard + 30;
	a = verif_angle(a);
	x = 0;
	while (x <= (env->nb_colonne))
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		printf("angle : %f\n", a);
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		h_percue = env->d_ecran * (env->h_mur / dist);
		affichage(h_percue, env, x);
		a = a - (60. / (env->nb_colonne));
		x++;
	}
}
