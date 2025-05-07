/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:16:17 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 07:52:13 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iterations, t_data *data)
{
	float	hue;
	int		r;
	int		g;
	int		b;

	if (iterations == MAX_ITERATIONS)
		return (0x000000);
	hue = 360.0 * iterations / (MAX_ITERATIONS / 2.0);
	hue = fmod(hue + data->color_shift, 360.0);
	r = (int)(127.5 * (1 + cos(hue * M_PI / 180.0)));
	g = (int)(127.5 * (1 + cos((hue - 120.0) * M_PI / 180.0)));
	b = (int)(127.5 * (1 + cos((hue + 120.0) * M_PI / 180.0)));
	return ((r << 16) | (g << 8) | b);
}

void	draw_julia(t_data *data)
{
	t_complex	z;
	int			iterations;
	int			color;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom)
				+ data->center_x;
			z.imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom)
				+ data->center_y;
			iterations = julia_iterations(z, data->c);
			color = get_color(iterations, data);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_mandelbrot(t_data *data)
{
	t_complex	c;
	int			iterations;
	int			color;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom)
				+ data->center_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom)
				+ data->center_y;
			iterations = mandelbrot_iterations(c);
			color = get_color(iterations, data);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	redraw(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->fractal_type == FRACT_JULIA)
		draw_julia(data);
	else if (data->fractal_type == FRACT_MANDELBROT)
		draw_mandelbrot(data);
	else if (data->fractal_type == FRACT_FERN)
		draw_barnsley_fern(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
