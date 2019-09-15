/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:07:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/15 10:16:27 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	draw_img(t_base *base)
{
	mlx_put_image_to_window(base->mlx->mlx_ptr, base->mlx->win_ptr,
	base->mlx->img_ptr, 0, 0);
	free_img(base);
}

void	free_img(t_base *base)
{
	int q;

	q = 0;
	while (q < base->width * base->height)
	{
		base->mlx->data_img[q] = 0;
		q++;
	}
}
