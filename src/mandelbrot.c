/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:09:14 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/07 19:20:08 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	mandelbrot(t_base *base)
{
	t_fract	*fract;
	t_complex	*z;

	fract = base->fract;
	while (fract->y < base->height)
	{
		fract->c->im = fract->max->im - fract->y * fract->factor->im;
		fract->x = 0;
		while (fract->x < base->width)
		{
			fract->c->re = fract->min->re + fract->x * fract->factor->re;
			z = init_com(fract->c->re, fract->c->im);
			fract->iteration = 0;
			while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4 && fract->iteration < fract->max_iteration)
			{
				z = init_com(pow(z->re, 2.0) - pow(z->im, 2.0) + fract->c->re,
							 2.0 * z->re * z->im + fract->c->im);
				fract->iteration++;
			}
			get_color(base);
			fract->x++;
		}
		fract->y++;
	}
	fract->y = 0;
}

void	get_color(t_base *base)
{
	base->mlx->data_img[(base->fract->y * base->width) +
	base->fract->x - 1] = get_color_two(base);
}

int		get_color_two(t_base *base)
{
	double  t;
	int		red;
	int 	green;
	int 	blue;

	t = (double)base->fract->iteration / (double)base->fract->max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}
