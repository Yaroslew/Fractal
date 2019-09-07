/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:41:05 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/26 21:54:14 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int		check(char *str)
{
	if (ft_strcmp("Mandelbrot", str) == 0)
		return (1);
	if (ft_strcmp("Julia", str) == 0)
		return (2);
	if (ft_strcmp("Mandelbar", str) == 0)
		return (3);
	mess_err(1);
	return (0);
}
