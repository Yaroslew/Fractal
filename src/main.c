/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:53 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/26 21:46:02 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static int de_key(int key, t_base *base)
{
	if (key == 53)
	{
		exit(0);
		base = NULL;
	}

	return (0);
}

int main (int ar, char **av)
{
	t_base *base;
	if (ar != 2)
		mess_err(1);
	base = init_base(check(av[1]));
	init_mlx(base);
	init_fract(base);
	if (base->type_fract == 1)
		mandelbrot(base);
	if (base->type_fract == 2)
		julia(base);

	draw_img(base);

	mlx_hook(base->mlx->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx->mlx_ptr);
}