/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:41:05 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/26 16:43:58 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractal.h"

int		check(char *str)
{
	if (ft_strcmp("Mandelbrot", str) == 0)
		return (1);
	if (ft_strcmp("Julia", str))
		return (2);
	mess_err(1);
	return (0);
}
