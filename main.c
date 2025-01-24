/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:34:14 by dcampas-          #+#    #+#             */
/*   Updated: 2025/01/24 12:31:04 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include "MLX42/mlx.h"

int main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0) 
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
{
		fractal.name = argv[1];
		//1
		fractal_init(&fractal);
		//2
		fractal_render(&fractal);
		
		//3
		mlx_loop(fractal.mlx_connection);

	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}