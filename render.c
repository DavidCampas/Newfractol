/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:58:58 by dcampas-          #+#    #+#             */
/*   Updated: 2025/01/24 12:54:22 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include "MLX42/mlx.h"


// Coloca un píxel en el buffer de la imagen
static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	//printf("Putting pixel at (%d, %d) with color %x\n", x, y, color); // Debugging line
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/*
 * EASY TOGGLE mandel & julia
*/
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
		
	//pixel coordinate x && y scaled to fit mandel
	z.x = (fractal_map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (fractal_map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

	mandel_vs_julia(&z, &c, fractal);
	//many times?
	while (i < fractal->iterations_definition)
	{
		//z = z^2 + c
		z = fractal_sum_complex(square_complex(z), c);
		//is the value scaped?
		
		//if hypo > 2 I assume the point is out
		if ((z.x *z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = fractal_map(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;

	}
	//we are in mandelbrot given the iterations
	my_pixel_put(x, y, &fractal->img, COLOR_RAINBOW);
}
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}