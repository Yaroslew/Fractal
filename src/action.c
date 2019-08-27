/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:21:12 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/27 19:12:52 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	zoom(t_base *base)
{
	double interpolation;

	interpolation = 1.0 / base->fract->zoom_factor;
	base->fract->min->re = interpolate(base->fract->mouse->re, base->fract->min->re, interpolation);
	base->fract->min->im = interpolate(base->fract->mouse->im, base->fract->min->im, interpolation);
	base->fract->max->re = interpolate(base->fract->mouse->re, base->fract->max->re, interpolation);
	base->fract->max->im = interpolate(base->fract->mouse->im, base->fract->max->im, interpolation);
}

double interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	set_mouse(t_base *base, int x, int y)
{
	base->fract->mouse->re = (double)x / (base->width / (base->fract->max->re - base->fract->min->re)) + base->fract->min->re;
	base->fract->mouse->im = (double)y / (base->height / (base->fract->max->im - base->fract->min->im)) + base->fract->min->im;
}
