/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:53 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/15 12:15:43 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static int	de_key(int key, t_base *base)
{
	if (key == 53)
	{
		exit(0);
		base = NULL;
	}
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_base *base)
{
	if (button == 4)
		base->fract->zoom_factor += base->fract->scale;
	if (button == 5)
		base->fract->zoom_factor -= base->fract->scale;
	set_mouse(base, x, y);
	zoom(base);
	if (base->type_fract == 1)
		mandelbrot(base);
	if (base->type_fract == 2)
		julia(base);
	if (base->type_fract == 3)
		mandelbar(base);
	draw_img(base);
	return (0);
}

static int	mouse_move(int x, int y, t_base *base)
{
	julia_motion(x, y, base);
	julia(base);
	draw_img(base);
	return (0);
}

static void	hook_event(t_base *base)
{
	mlx_mouse_hook(base->mlx->win_ptr, mouse_hook, base);
	if (base->type_fract == 2)
		mlx_hook(base->mlx->win_ptr, 6, 0, mouse_move, base);
	mlx_hook(base->mlx->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx->mlx_ptr);
}

int			main(int ar, char **av)
{
	t_base	*base;

	if (ar != 2)
		mess_err(1);
	base = init_base(check(av[1]));
	init_fract(base);
	if (base->type_fract == 1)
		mandelbrot(base);
	if (base->type_fract == 2)
		julia(base);
	if (base->type_fract == 3)
		mandelbar(base);
	draw_img(base);
	hook_event(base);
	return (0);
}
