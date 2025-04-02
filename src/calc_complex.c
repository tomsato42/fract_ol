/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:14:28 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 07:14:58 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imag * z.imag;
	result.imag = 2 * z.real * z.imag;
	return (result);
}

t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imag = z1.imag + z2.imag;
	return (result);
}

double	complex_abs_squared(t_complex z)
{
	return (z.real * z.real + z.imag * z.imag);
}
