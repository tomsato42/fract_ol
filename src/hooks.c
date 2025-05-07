/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:38:15 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 08:57:29 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_fern_zoom(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->zoom *= 1.2;
	else
		data->zoom /= 1.2;
	data->center_x += (double)(x - WIDTH / 2) / (WIDTH * data->zoom) * 0.1;
	data->center_y += (double)(HEIGHT / 2 - y) / (HEIGHT * data->zoom) * 0.1;
}

static void	handle_fractal_zoom(int button, int x, int y, t_data *data)
{
	double	real_before;
	double	imag_before;
	double	real_after;
	double	imag_after;

	real_before = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom)
		+ data->center_x;
	imag_before = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom)
		+ data->center_y;
	if (button == 4)
		data->zoom *= 1.2;
	else
		data->zoom /= 1.2;
	real_after = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom)
		+ data->center_x;
	imag_after = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom)
		+ data->center_y;
	data->center_x += (real_before - real_after);
	data->center_y += (imag_before - imag_after);
}

static void	handle_key_movement(int keycode, t_data *data)
{
	double	move_amount;

	move_amount = 0.1 / data->zoom;
	if (keycode == KEY_UP)
		data->center_y -= move_amount;
	else if (keycode == KEY_DOWN)
		data->center_y += move_amount;
	else if (keycode == KEY_LEFT)
	{
		if (data->fractal_type == FRACT_FERN)
			data->center_x += move_amount;
		else
			data->center_x -= move_amount;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (data->fractal_type == FRACT_FERN)
			data->center_x -= move_amount;
		else
			data->center_x += move_amount;
	}
	redraw(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		clean_exit(data);
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		handle_key_movement(keycode, data);
	else if (keycode == KEY_SPACE)
	{
		if (data->animate_colors)
			data->animate_colors = 0;
		else
			data->animate_colors = 1;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
	{
		if (data->fractal_type == FRACT_FERN)
			handle_fern_zoom(button, x, y, data);
		else
			handle_fractal_zoom(button, x, y, data);
		redraw(data);
	}
	return (0);
}
