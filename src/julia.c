/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:21:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/07 20:01:43 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void			julia(t_base *base)
{
	t_fract		*fract;
	t_complex	*z;

	fract = base->fract;
	while (fract->y < base->height)
	{
		fract->c->im = fract->max->im - fract->y * fract->factor->im;
		fract->x = -1;
		while (fract->x++ < base->width)
		{
			fract->c->re = fract->min->re + fract->x * fract->factor->re;
			z = init_com(fract->c->re, fract->c->im);
			fract->iteration = 0;
			while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4 && fract->iteration <
					fract->max_iteration)
			{
				z = init_com(pow(z->re, 2.0) - pow(z->im, 2.0) + fract->k->re,
						2.0 * z->re * z->im + fract->k->im);
				fract->iteration++;
			}
			get_color(base);
		}
		fract->y++;
	}
	fract->y = 0;
}
