/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:57 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/06 19:34:46 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <stdlib.h>
#include <math.h>
# include "mlx.h"

typedef struct s_base
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int		*img_data;
	int		width;
	int		height;

	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;

	double	factor_re;
	double	factor_im;

	int		max_iteration;
	int		iteration;
}			t_base;

typedef struct s_complex
{
	double	im;
	double	re;
}				t_complex;

void			mess_err(int a);
t_complex		*init_com(double re, double im);
void			maldebrot(t_base *base);
int				get_color(int iteration, int max_itaretion);
void			check_av(char **av);

#endif
