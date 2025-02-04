/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:31:50 by dcampas-          #+#    #+#             */
/*   Updated: 2025/02/04 15:57:10 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "MLX42/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"\
		./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define HEIGHT	800
# define WIDTH	800

//***COLORS***
# define COLOR_BLACK					0x000000  // Negro
# define COLOR_WHITE					0xFFFFFF  // Blanco
# define COLOR_RED					0xFF0000  // Rojo
# define COLOR_GREEN					0x00FF00  // Verde
# define COLOR_BLUE					0x0000FF  // Azul
# define COLOR_YELLOW				0xFFFF00  // Amarillo
# define COLOR_MAGENTA				0xFF00FF  // Magenta
# define COLOR_CYAN					0x00FFFF  // Cian

// Colores psicodélicos
# define COLOR_FLUORESCENT_ORANGE	0xFF6700 // Naranja fluorescente
# define COLOR_ACID_YELLOW			0xCCFF00  // Amarillo ácido
# define COLOR_LIME_GREEN			0x32CD32  // Verde lima
# define COLOR_TURQUOISE				0x40E0D0  // Turquesa
# define COLOR_HOT_PINK				0xFF69B4  // Rosa intenso
# define COLOR_RAINBOW				0xDA70D6  // Arco iris (mezcla psicodélica)
# define COLOR_PSYCHEDELIC_RED		0xFF4500 // Rojo psicodélico

/*
	*FRACTAL ID
	* ~ MLX stuff
	* ~ Image
	* ~ Hooks value
*/
//***Complex value***
typedef struct s_complex
{
	//real
	double	x;
	//i
	double	y;
}	t_complex;

//***IMAGE***
//pixels buffer values from mlx_get_data_addr()
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_fractal
{
	//MLX
	char	*name;
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; // mlx_nw_window()
	//Image
	t_image	img;
	//Hooks member vble TODO
	double	escape_value; //hypotenuse
	int		iterations_definition; //value that increase the image quality
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractal;

typedef struct s_scale
{
	double	unscalednum;
	double	minallowed;
	double	maxallowed;
	double	min;
	double	max;
}	t_scale;

//*** String utils ****
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atodbl(char *str);

//*** Init ***
void		fractal_init(t_fractal *fractal);

//*** Render ***
void		fractal_render(t_fractal *fractal);

//*** Math ***
double		fractal_map(t_scale *params);
t_complex	fractal_sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//*** Hooks_events ***
int			key_handler(int keysym, t_fractal *fractal);

//*** Clean_up ***
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif