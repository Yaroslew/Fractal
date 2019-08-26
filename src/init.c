/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:44:48 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/26 21:45:39 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractal.h"

t_base *init_base(int a)
{
	t_base *base;

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

void	init_fract(t_base *base)
{
	if (!(base->fract = malloc(sizeof(t_fract) * 1)))
		mess_err(0);
	base->fract->min = init_com(-2.0, -2.0);
	base->fract->max = init_com(2.0, base->fract->min->im + (2.0 -
	base->fract->min->re) * base->height / base->width);
	base->fract->factor = init_com((base->fract->max->re - base->fract->min->re)
	/ (base->width - 1), (base->fract->max->im - base->fract->min->im) / (base->height - 1));
	base->fract->iteration = 0;
	base->fract->max_iteration = 50;
	base->fract->x = 0;
	base->fract->y = 0;
	base->fract->c = init_com(0, 0);
	base->fract->k = init_com(-0.4, 0.6);

}

t_complex	*init_com(double re, double im)
{
	t_complex *complex;

	if (!(complex = malloc(sizeof(t_complex) * 1)))
		mess_err(0);
	complex->im = im;
	complex->re = re;
	return (complex);
}

void	init_mlx(t_base *base)
{
	int pix;
	int end;
	int line;

	if (!(base->mlx = malloc(sizeof(t_mlx) * 1)))
		mess_err(0);
	base->mlx->mlx_ptr = mlx_init();
	base->mlx->win_ptr = mlx_new_window(base->mlx->mlx_ptr, base->width, base->height, "Fractal");
	base->mlx->img_ptr = mlx_new_image(base->mlx->mlx_ptr, base->width, base->height);
	base->mlx->data_img = (int *)mlx_get_data_addr(base->mlx->img_ptr, &pix, &line, &end);
}