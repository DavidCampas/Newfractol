/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:43:59 by dcampas-          #+#    #+#             */
/*   Updated: 2025/02/04 12:43:59 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * ESC or i press the x🔴 in the window
 * there won't be leaks!
 * int (*f)(void *param)
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
				fractal	img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
					fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*
 * Keypress prototype
 * int (*f)(int keycode, void *param)
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	fractal_checker = 0;
	if (keysym == XK_Escape)
	{
		close_handler(fractal);
	}
	if (keysym == XK_Left)
	{
		fractal->shift_x += (0.5 * fractal->zoom);
	}
	else if (keysym == XK_Right)
	{
		fractal->shift_x -= (0.5 * fractal->zoom);
	}
	else if (keysym == XK_Up)
	{
		fractal->shift_y += (0.5 * fractal->zoom);
	}
	else if (keysym == XK_Down)
	{
		fractal->shift_y -= (0.5 * fractal->zoom);
	}
	else if (keysym == XK_plus)
	{
		fractal->iterations_definition += 10;
	}
	else if (keysym == XK_minus)
	{
		fractal->iterations_definition -= 10;
	}
	//Refresh
	fractal_render(fractal);
	return (0);
}

/*
 * int (*f)(int button, int x, int y, void *param)
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	//Zoom in
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	//Zoom out
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	// refresh
	fractal_render(fractal);
	return 0;
}

/*
 * TRACK the mouse
 * to change julia dynamically
 * int (*f)(int x, int y, void *param)
*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	static int	last_x = 0;
	static int	last_y = 0;

	if (abs(x - last_x) > 5 || abs(y - last_y) > 5)
	{
		last_x = x;
		last_y = y;
		if (!ft_strncmp(fractal->name, "julia", 5))
		{
			fractal->julia_x = (fractal_map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
			fractal->julia_y = (fractal_map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
			fractal_render(fractal);
		}
	}
	return 0;
}