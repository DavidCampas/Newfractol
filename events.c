#include "fractol.h"

/*
 * ESC or i press the x🔴 in the window
 * there won't be leaks!
 * int (*f)(void *param)
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.img_ptr);
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
	static int	fractal_checker;

	fractal_checker = 0;
	if (keysym == XK_Escape)
	{
		close_handler(fractal);
		fractal_checker = 1;
	}
	if (keysym == XK_Left)
	{
		fractal->shift_x += (0.5 * fractal->zoom);
		fractal_checker = 1;
	}
	else if (keysym == XK_Right)
	{
		fractal->shift_x -= (0.5 * fractal->zoom);
		fractal_checker = 1;
	}
	else if (keysym == XK_Up)
	{
		fractal->shift_y += (0.5 * fractal->zoom);
		fractal_checker = 1;
	}
	else if (keysym == XK_Down)
	{
		fractal->shift_y -= (0.5 * fractal->zoom);
		fractal_checker = 1;
	}
	else if (keysym == XK_plus)
	{
		fractal->iterations_definition += 10;
		fractal_checker = 1;
	}
	else if (keysym == XK_minus)	
	{
		fractal->iterations_definition -= 10;
		fractal_checker = 1;
	}
	// refresh the image
	fractal_render(fractal);
	return 0;
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
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (fractal_map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (fractal_map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return 0;
}