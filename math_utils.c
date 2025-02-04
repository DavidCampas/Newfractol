/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:08:32 by dcampas-          #+#    #+#             */
/*   Updated: 2025/02/04 15:57:49 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Escala un numero de un rango a otro.
double	fractal_map(t_scale *params)
{
	if (params->max == params->min)
	{
		fprintf(stderr, "Error: Division by zero in map function.\n");
		return (params->minallowed);
	}
	return ((params->maxallowed - params->minallowed)
		* (params->unscalednum - params->min)
		/ (params->max - params->min) + params->minallowed);
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
