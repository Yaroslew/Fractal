/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:06:53 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/03 18:50:11 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"
# define ERROR(data)						\
	if ((data))							\
	{											\
		printf("{red!}Error\n");	\
		printf("file : %s\n", __FILE__);		\
		printf("function : %s\n", __func__);	\
		printf("line : %d\n", __LINE__);		\
		exit(1);								\
	}
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




int main (int ar, char **av)
{
	t_base *base;

//	int 	ret;
//	char *source_str = ft_strdup("__kernel void test(__global int* message) \
//{ \
//	int gid = get_global_id(0);\
//\
//\
//	message[gid] = 0xFF0000;\
//}");
//	cl_platform_id 	platform_id;
//	cl_uint 	ret_num_platforms;
//	cl_device_id  	device_id;
//	cl_uint 	ret_num_devices;
//	cl_context context;
//	cl_command_queue command_queue;
//	ret = clGetPlatformIDs(1, &platform_id, NULL);
//	//ft_printf("->>>%d<<--", ret);
//	ERROR(ret);
//
//	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
//	ERROR(ret);
//	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
//	ERROR(ret);
//	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
//	ERROR(ret);
//
//
//	cl_program program = NULL;
//	cl_kernel kernel = NULL;
//	size_t source_size = ft_strlen(source_str);
//	program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
//	ERROR(ret);
//	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	ERROR(ret);
//	kernel = clCreateKernel(program, "test", &ret);
//	ERROR(ret);
//
//
//	cl_mem memobj = NULL;
//	int memLenth = 10;
//	cl_int* mem = (cl_int *)malloc(sizeof(cl_int) * memLenth);
//
///* создать буфер */
//	memobj = clCreateBuffer(context, CL_MEM_READ_WRITE, memLenth * sizeof(cl_int), NULL, &ret);
//	ERROR(ret);
//
///* записать данные в буфер */
//	ret = clEnqueueWriteBuffer(command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(cl_int), mem, 0, NULL, NULL);
//	ERROR(ret);
//
///* устанавливаем параметр */
//	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);
//	ERROR(ret);
//	size_t global_work_size[1] = { 10 };
//
///* выполнить кернел */
//	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);
//	ERROR(ret);
///* считать данные из буфера */
//	ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(float), mem, 0, NULL, NULL);
//	ERROR(ret);

//	int i = 0;
//	while (i < 10)
//		ft_printf("%d\n", mem[i++]);
	if (ar != 2)
		mess_err(1);
	base = init_base(check(av[1]));
	init_mlx(base);
	init_fract(base);
	if (base->type_fract == 1)
		mandelbrot(base);
	if (base->type_fract == 2)
		julia(base);
	if (base->type_fract == 3)
		mandelbar(base);
	draw_img(base);

	mlx_mouse_hook(base->mlx->win_ptr, mouse_hook, base);
	mlx_hook(base->mlx->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx->mlx_ptr);
}