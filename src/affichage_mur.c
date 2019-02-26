/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/26 15:27:51 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		affichage(double h_percue, t_env *env, int x, float a)
{
	float	y;
	float	lim;

	lim = (env->h_regard - (h_percue / 2));
	y = -1.;
	while (++y < lim && y < 870.)
		put_pxl_img(env, x, y, 6);
	y--;
	lim = (env->h_regard + (h_percue / 2));
	if (env->orientation == 1)
	{
		while (a >= 0. && a < 180. && ++y <= lim && y < 870.)
			put_pxl_img(env, x, y, 11);
		while (!(a >= 0. && a < 180.) && ++y <= lim && y < 870.)
			put_pxl_img(env, x, y, 9);
	}
	else if (env->orientation == 2)
	{
		while (a >= 90. && a < 270. && ++y <= lim && y < 870.)
			put_pxl_img(env, x, y, 8);
		while (!(a >= 90. && a < 270.) && ++y <= lim && y < 870.)
			put_pxl_img(env, x, y, 10);
	}
	y--;
	while (++y < 870.)
		put_pxl_img(env, x, y, 7);
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
	while (x < (env->nb_colonne))
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		h_percue = env->d_ecran * (env->h_mur / dist);
		affichage(h_percue, env, x, env->angle);
		a -= (60. / (env->nb_colonne));
		x++;
	}
}
