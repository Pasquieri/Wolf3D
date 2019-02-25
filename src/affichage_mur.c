/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_mur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:27:02 by cpalmier          #+#    #+#             */
/*   Updated: 2019/02/25 11:50:50 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		affichage(double h_percue, t_env *env, int x)
{
	float	y;
	float	min;
	float	max;

	min = (env->h_regard - (h_percue / 2));
	max = (env->h_regard + (h_percue / 2));
	y = -1.;
	while (++y < min && y < 870.)
		put_pxl_img(env, x, y, 6);
	y--;
	while (++y <= max && y < 870.)
	{
		/*if (env->angle >= 45. && env->angle < 135.)
			put_pxl_img(env, x, y, 8);
		else if (env->angle >= 135. && env->angle < 225.)
			put_pxl_img(env, x, y, 9);
		else if (env->angle >= 225. && env->angle < 315.)
			put_pxl_img(env, x, y, 10);
		else
			put_pxl_img(env, x, y, 11);*/
		put_pxl_img(env, x, y, 5);
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
	while (x <= (env->nb_colonne))
	{
		env->angle = a;
		env->angle = verif_angle(env->angle);
		dist = detection_mur(env);
		dist = dist * cos((a - env->d_regard) * M_PI / 180);
		h_percue = env->d_ecran * (env->h_mur / dist);
		affichage(h_percue, env, x);
		a -= (60. / (env->nb_colonne));
		x++;
	}
}
