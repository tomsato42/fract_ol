/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:15:38 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 07:21:27 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iterations(t_complex z, t_complex c)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	temp;

	i = 0;
	z_real = z.real;
	z_imag = z.imag;
	while (i < MAX_ITERATIONS && (z_real * z_real + z_imag * z_imag) < 4.0)
	{
		temp = z_real;
		z_real = z_real * z_real - z_imag * z_imag + c.real;
		z_imag = 2 * temp * z_imag + c.imag;
		i++;
	}
	return (i);
}

int	mandelbrot_iterations(t_complex c)
{
	t_complex	z;
	int			i;

	i = 0;
	z.real = 0;
	z.imag = 0;
	while (i < MAX_ITERATIONS - 4 && complex_abs_squared(z) < 4.0)
	{
		z = complex_add(complex_square(z), c);
		if (complex_abs_squared(z) >= 4.0)
			return (i + 1);
		z = complex_add(complex_square(z), c);
		if (complex_abs_squared(z) >= 4.0)
			return (i + 2);
		z = complex_add(complex_square(z), c);
		if (complex_abs_squared(z) >= 4.0)
			return (i + 3);
		z = complex_add(complex_square(z), c);
		i += 4;
	}
	while (i++ < MAX_ITERATIONS && complex_abs_squared(z) < 4.0)
		z = complex_add(complex_square(z), c);
	return (i);
}
