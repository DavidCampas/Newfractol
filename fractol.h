#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "MLX42/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1. <value_2>\"\n"
#define HEIGHT	800
#define WIDTH	800

//***COLORS***
#define COLOR_BLACK        0x000000  // Negro
#define COLOR_WHITE        0xFFFFFF  // Blanco
#define COLOR_RED          0xFF0000  // Rojo
#define COLOR_GREEN        0x00FF00  // Verde
#define COLOR_BLUE         0x0000FF  // Azul
#define COLOR_YELLOW       0xFFFF00  // Amarillo
#define COLOR_MAGENTA      0xFF00FF  // Magenta
#define COLOR_CYAN         0x00FFFF  // Cian

// Colores psicodélicos
#define COLOR_NEON_PINK    0xFF6EC7  // Rosa neón
#define COLOR_NEON_GREEN   0x39FF14  // Verde neón
#define COLOR_NEON_BLUE    0x1B03A3  // Azul neón
#define COLOR_ELECTRIC_PURPLE 0xBF00FF // Púrpura eléctrico
#define COLOR_FLUORESCENT_ORANGE 0xFF6700 // Naranja fluorescente
#define COLOR_ACID_YELLOW  0xCCFF00  // Amarillo ácido
#define COLOR_LIME_GREEN   0x32CD32  // Verde lima
#define COLOR_TURQUOISE    0x40E0D0  // Turquesa
#define COLOR_HOT_PINK     0xFF69B4  // Rosa intenso
#define COLOR_RAINBOW      0xDA70D6  // Arco iris (mezcla psicodélica)
#define COLOR_PSYCHEDELIC_RED 0xFF4500 // Rojo psicodélico

/*
	*FRACTAL ID
	* ~ MLX stuff
	* ~ Image
	* ~ Hooks value
*/

//***Complex value***
typedef	struct s_complex
{
	//real
	double	x;
	//i
	double	y;
}	t_complex;

//***IMAGE***
//pixels buffer values from mlx_get_data_addr()
typedef	struct s_img
{
	
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_image;


typedef struct	s_fractal
{
	//MLX
	char	*name;

	void	*mlx_connection; //mlx_init()
	void	*mlx_window; // mlx_nw_window()

	//Image
	t_image	img;

	//Hooks member vble TODO
	double	escape_value; //hypotenuse
	int		itertions_definition; //value that increase the image quality
	
}	t_fractal;

//***String utils****
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//***Init***
void	fractal_init(t_fractal *fractal);

//***Render***
void	fractal_render(t_fractal *fractal);

//***Math***
double		fractal_map(double unscaledNum, double minAllowed, double maxAllowed, double min, double max);
t_complex	fractal_sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);



//void	draw_pixels(t_image *img, int x, int y, int color);
#endif