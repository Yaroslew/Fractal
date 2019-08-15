/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mald.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:38:22 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/15 17:34:41 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

t_complex	*init_com(double re, double im)
{
	t_complex	*complex;

	if(!(complex = malloc(sizeof(t_complex) * 1)))
		mess_err(0);
	complex->re = re;
	complex->im = im;
	return (complex);
}

int			get_color(int iteration, int max_iteration)
{
	double	iter;
	int		red;
	int		green;
	int		blue;

	iter = (double)iteration / (double)max_iteration;
	red = (int)(9 * (1 - iter) * pow(iter, 3) * 255);
	green = (int)(15 * pow((1 - iter), 2) * pow(iter, 2) * 255);
	blue = (int)(8.5 * pow((1 - iter), 3) * iter * 255);
	return ((red << 16) | (green << 8) | blue);
}

void	maldebrot(t_base *base)
{
	int		x;
	int		y;
	t_complex	*z;
	double	c_re;
	double	c_im;

	y = 0;
	x = 0;
	while (y < base->height)
	{
		c_im = base->max_im - y * base->factor_im * base->scale;
		x = 0;
		while (x < base->width)
		{
			c_re = base->min_re + x * base->factor_re * base->scale;
			z = init_com(c_re, c_im);
			base->iteration = 0;
			while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4 && base->iteration < base->max_iteration)
			{
				z = init_com(pow(z->re, 2.0) - pow(z->im, 2.0) + c_re,
						2.0 * z->re * z->im + c_im);
				base->iteration++;
			}
			base->img_data[(y * base->width) + x - 1] = get_color(base->iteration, base->max_iteration);
			x++;
		}
		y++;
	}
}