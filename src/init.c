/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:44:48 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/08 11:30:21 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static t_complex	*pre_init_fract(double re, double im, t_complex *complex)
{
	if (!(complex = malloc(sizeof(t_complex) * 1)))
		mess_err(0);
	init_com(re, im, complex);
	return (complex);
}

t_base			*init_base(int a)
{
	t_base	*base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	base->height = 500;
	base->width = 500;
	base->type_fract = a;
	if (!(base->mlx = malloc(sizeof(t_mlx) * 1)))
		mess_err(0);
	init_mlx(base);
	return (base);
}

void			init_fract(t_base *base)
{
	if (!(base->fract = malloc(sizeof(t_fract) * 1)))
		mess_err(0);
	base->fract->min = pre_init_fract(-2.0, -2.0, base->fract->min);
	base->fract->max = pre_init_fract(2.0, base->fract->min->im + (2.0 -
	base->fract->min->re) * base->height / base->width, base->fract->max);
	base->fract->factor = pre_init_fract((base->fract->max->re - base->fract->min->re)
	/ (base->width - 1), (base->fract->max->im - base->fract->min->im) /
	(base->height - 1), base->fract->factor);
	base->fract->iteration = 0;
	base->fract->max_iteration = 50;
	base->fract->x = 0;
	base->fract->y = 0;
	base->fract->z = pre_init_fract(0, 0, base->fract->z);
	base->fract->c = pre_init_fract(0, 0, base->fract->c);
	base->fract->k = pre_init_fract(-0.4, 0.6, base->fract->k);
	base->fract->mouse = pre_init_fract(0, 0, base->fract->mouse);
	base->fract->zoom_factor = 1.0;
	base->fract->scale = 0.01;
}

void			init_com(double re, double im, t_complex *complex)
{
	complex->im = im;
	complex->re = re;
	return ;
}

void			init_mlx(t_base *base)
{
	int			pix;
	int			end;
	int			line;

	base->mlx->mlx_ptr = mlx_init();
	base->mlx->win_ptr = mlx_new_window(base->mlx->mlx_ptr,
			base->width, base->height, "Fract'ol");
	base->mlx->img_ptr = mlx_new_image(base->mlx->mlx_ptr,
			base->width, base->height);
	base->mlx->data_img = (int *)mlx_get_data_addr(base->mlx->img_ptr,
			&pix, &line, &end);
}
