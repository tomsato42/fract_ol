/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:01:25 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 10:21:27 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define E_MSG_1 "Error: Invalid argument\n"
#define E_MSG_2 "Usage: ./fractol j [real] [imag] (for Julia set)\n"
#define E_MSG_3 "       ./fractol m (for Mandelbrot set)\n"
#define E_MSG_4 "       ./fractol f (for Barnsley fern)\n"

void	init_fractal_data(t_data *data, char fractal_type)
{
	char	*title;

	data->fractal_type = fractal_type;
	if (fractal_type == FRACT_JULIA)
		title = "Julia Set";
	else if (fractal_type == FRACT_MANDELBROT)
		title = "Mandelbrot Set";
	else
		title = "Barnsley Fern";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->c.real = -0.7;
	data->c.imag = 0.27015;
	data->zoom = INITIAL_ZOOM;
	data->color_shift = 0;
	data->animate_colors = 0;
	data->center_x = 0.0;
	data->center_y = 0.0;
	if (fractal_type == FRACT_MANDELBROT)
		data->center_x = -0.5;
}

void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, animate_colors, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || (argv[1][0] != FRACT_JULIA && argv[1][0] != FRACT_MANDELBROT
			&& argv[1][0] != FRACT_FERN) || argv[1][1] != '\0')
	{
		ft_printf("%s%s%s%s", E_MSG_1, E_MSG_2, E_MSG_3, E_MSG_4);
		return (1);
	}
	init_fractal_data(&data, argv[1][0]);
	if (data.fractal_type == 'j' && argc >= 4)
	{
		data.c.real = ft_atof(argv[2]);
		data.c.imag = ft_atof(argv[3]);
	}
	if (data.fractal_type == FRACT_JULIA)
		draw_julia(&data);
	else if (data.fractal_type == FRACT_MANDELBROT)
		draw_mandelbrot(&data);
	else if (data.fractal_type == FRACT_FERN)
		draw_barnsley_fern(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
