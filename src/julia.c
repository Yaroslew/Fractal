/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:21:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/08 11:13:49 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void			julia(t_base *base)
{
	t_fract		*fract;

	fract = base->fract;
	while (fract->y < base->height)
	{
		fract->c->im = fract->max->im - fract->y * fract->factor->im;
		fract->x = -1;
		while (fract->x++ < base->width)
		{
			fract->c->re = fract->min->re + fract->x * fract->factor->re;
			init_com(fract->c->re, fract->c->im, fract->z);
			fract->iteration = 0;
			while (pow(fract->z->re, 2.0) + pow(fract->z->im, 2.0) <= 4 && fract->iteration <
					fract->max_iteration)
			{
				init_com(pow(fract->z->re, 2.0) - pow(fract->z->im, 2.0) + fract->k->re,
						2.0 * fract->z->re * fract->z->im + fract->k->im, fract->z);
				fract->iteration++;
			}
			get_color(base);
		}
		fract->y++;
	}
	fract->y = 0;
}
