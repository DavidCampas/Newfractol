/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:08:32 by dcampas-          #+#    #+#             */
/*   Updated: 2025/01/24 11:22:07 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Escala un numero de un rango a otro.
double	fractal_map(double unscaledNum, double minAllowed, double maxAllowed, double min, double max)
{
	if (max == min)
	{
		fprintf(stderr, "Error: Division by zero in map function.\n");
		return (minAllowed);
	}
	return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}

//SUM complex
t_complex	fractal_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

//Square	real = (x^2 - y^2)
//			ima = 2xy
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}