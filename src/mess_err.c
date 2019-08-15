/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mess_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:16:30 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/15 17:34:41 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	mess_err(int a)
{
	if (a == 0)
		ft_printf("Не выделена память. Чекай маллок\n");
	if (a == 1)
		ft_printf("Не указан или неправильно написан вызваемый фрактал.\n"
			"./fractal Mandelbrot - множество Мальдеброта\n"
  			"./fractal Jul - множество Жулиа\n"
			"./fractal Ser - треугольник Серпинского\n");
	exit(0);
}

void	check_av(char **av)
{
	int 	sum;

	sum = 0;
	if (ft_strcmp(av[1], "Mandelbrot"))
		sum = 1;
}