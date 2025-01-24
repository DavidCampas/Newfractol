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

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	//1 iteration
	z.x = 0.0;
	z.y = 0.0;
	
	//pixel coordinate x && y scaled to fit mandel
	c.x = fractal_map(x, 0, WIDTH, -2.0, 2.0);
	c.y = fractal_map(y, 0, HEIGHT, -2.0, 2.0);

	printf(" %d  %d\n", i, fractal->itertions_definition);
	//many times?
	while (i < fractal->itertions_definition)
	{
		printf(" new %d  new %d\n", i, fractal->itertions_definition);
		//z = z^2 + c
		z = fractal_sum_complex(square_complex(z), c);
		
		//is the value scaped?
		//if hypo > 2 I assume the point is out
		if ((z.x *z.x) + (z.y * z.y) > 4)
		{
			printf("estoy haciendo eso\n");
			color = COLOR_CYAN;
			//+ (i * 255 / fractal->itertions_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;

	}
	//we are in mandelbrot given the iterations
	//my_pixel_put(x, y, &fractal->img, COLOR_CYAN);
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