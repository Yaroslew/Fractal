/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:53 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/15 19:34:07 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static t_base	*init_base(void)
{
	t_base	*base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	base->width = 500;
	base->height = 500;

	base->min_re = -2.0;
	base->max_re = 2.0;
	base->min_im = -2.0;
	base->max_im = base->min_im + (base->max_re - base->min_re) * base->height / base->width;

	base->factor_re = (base->max_re - base->min_re) / (base->width - 1);
	base->factor_im = (base->max_im - base->min_im) / (base->height - 1);
	base->scale = 1.0;

	base->max_iteration = 50;

	return (base);
}

static void	init_mlx(t_base *base)
{
	int bits;
	int line;
	int endian;

	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, base->width, base->height, "Fractal");
	base->img_ptr = mlx_new_image(base->mlx_ptr, base->width, base->height);
	base->img_data = (int*)mlx_get_data_addr(base->img_ptr, &bits, &line, &endian);
}

static int de_key(int key, t_base *base)
{
	if (key == 53)
		exit(0);
	return (0);
}

static	int	mouse_hook(int button, int x, int y, t_base *base)
{
//	if (button == 4)
//		base->scale += -0.01;
//	if (button == 5)
//		base->scale += 0.01;


	ft_printf("%lf %lf\n", base->factor_im, base->factor_re);
	free_image(base);
	maldebrot(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
	return (0);
}

int	main (int ar, char **av)
{
	t_base *base;

//	if (ar < 2)
//		mess_err(1);
//	else
//		check_ar(av);
	base = init_base();
	init_mlx(base);
	maldebrot(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);

	mlx_mouse_hook(base->win_ptr, mouse_hook, base);
	mlx_hook(base->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx_ptr);

}