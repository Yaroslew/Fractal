/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:53 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/29 19:47:32 by pcorlys-         ###   ########.fr       */
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

static	int	mouse_hook(int button, int x, int y, t_base *base)
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

static void	*start_fractal(void *param)
{
	t_base *base;

	base = param;
	if (base->type_fract == 1)
		mandelbrot(base);
	if (base->type_fract == 2)
		julia(base);
	if (base->type_fract == 3)
		mandelbar(base);

	draw_img(base);
	pthread_exit(0);


	return (NULL);
}

int main (int ar, char **av)
{
	pthread_t	first;
	pthread_t	second;
	t_base *base;


	if (ar != 2)
		mess_err(1);
	base = init_base(check(av[1]));
	init_mlx(base);
	init_fract(base);

	base->height /= 2;
	pthread_create(&first, NULL, start_fractal, ((void*)base));
	base->fract->y = base->height;
	base->height *= 2;
	pthread_create(&second, NULL, start_fractal, ((void*)base));

	mlx_mouse_hook(base->mlx->win_ptr, mouse_hook, base);
	mlx_hook(base->mlx->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx->mlx_ptr);
}