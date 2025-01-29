/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:21:24 by dcampas-          #+#    #+#             */
/*   Updated: 2025/01/29 13:54:28 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "MLX42/mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	malloc_error(void)
{
	perror("Error: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;//2 squared the hypotenise
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	// zoom factor
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			MotionNotify,
			PointerMotionMask,
			julia_track,
			fractal);
}

void	fractal_init(t_fractal *fractal)
{
	//MLX stuff
	fractal->mlx_connection = mlx_init();
	if (fractal -> mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}