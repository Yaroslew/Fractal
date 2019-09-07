/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:57 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/07 16:44:20 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <stdlib.h>
#include <math.h>
# include "mlx.h"

typedef struct s_complex
{
	double		re;
	double 		im;
}				t_complex;

typedef struct s_fract
{
	int			iteration;
	int			max_iteration;
	int			x;
	int			y;
	double		zoom_factor;
	double		scale;

	t_complex	*max;
	t_complex	*min;
	t_complex	*c;
	t_complex	*factor;
	t_complex	*k;
	t_complex	*mouse;


}				t_fract;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data_img;

}				t_mlx;

typedef struct	s_base
{
	int			width;
	int			height;
	int			type_fract;
	t_fract		*fract;
	t_mlx		*mlx;


}				t_base;

void			mess_err(int a);
int				check(char *str);

t_base 			*init_base(int a);
t_complex		*init_com(double re, double im);
void			init_fract(t_base *base);
void			init_mlx(t_base *base);

void			mandelbrot(t_base *base);
void			julia(t_base *base);
void			mandelbar(t_base *base);
void			get_color(t_base *base);
int				get_color_two(t_base *base);

void			draw_img(t_base *base);
void			free_img(t_base *base);

void			set_mouse(t_base *base, int x, int y);
double 			interpolate(double start, double end, double interpolation);
void			zoom(t_base *base);
void 			julia_motion(int x, int y, t_base *base);


#endif
