/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:55:13 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 10:22:13 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_fern_params
{
	double		x;
	double		y;
	double		next_x;
	double		next_y;
	double		scale;
	double		offset_x;
	double		offset_y;
	int			screen_x;
	int			screen_y;
	int			color;
	double		r;
}				t_fern_params;

unsigned int	my_rand(void)
{
	static unsigned int	my_rand_state;

	if (my_rand_state == 0)
	{
		my_rand_state = 42;
	}
	my_rand_state = (my_rand_state * 1103515245 + 12345) & 0x7fffffff;
	return (my_rand_state);
}

void	init_fern_params(t_fern_params *params, t_data *data)
{
	params->x = 0;
	params->y = 0;
	params->scale = 50 * data->zoom;
	params->offset_x = WIDTH / 2 - data->center_x * params->scale * 4;
	params->offset_y = HEIGHT - 50 - data->center_y * params->scale * 10;
}

void	apply_fern_transform(t_fern_params *params)
{
	params->r = (double)my_rand() / RAND_MAX;
	if (params->r < 0.01)
	{
		params->next_x = 0;
		params->next_y = 0.16 * params->y;
	}
	else if (params->r < 0.86)
	{
		params->next_x = 0.85 * params->x + 0.04 * params->y;
		params->next_y = -0.04 * params->x + 0.85 * params->y + 1.6;
	}
	else if (params->r < 0.93)
	{
		params->next_x = 0.2 * params->x - 0.26 * params->y;
		params->next_y = 0.23 * params->x + 0.22 * params->y + 1.6;
	}
	else
	{
		params->next_x = -0.15 * params->x + 0.28 * params->y;
		params->next_y = 0.26 * params->x + 0.24 * params->y + 0.44;
	}
	params->x = params->next_x;
	params->y = params->next_y;
}

void	plot_fern_point(t_fern_params *params, t_data *data)
{
	params->screen_x = (int)(params->x * params->scale + params->offset_x);
	params->screen_y = (int)(HEIGHT - (params->y * params->scale)
			- data->center_y * 100);
	if (params->screen_x >= 0 && params->screen_x < WIDTH
		&& params->screen_y >= 0 && params->screen_y < HEIGHT)
	{
		params->color = get_color((int)(params->y * 10) % MAX_ITERATIONS, data);
		my_mlx_pixel_put(data, params->screen_x, params->screen_y,
			params->color);
	}
}

void	draw_barnsley_fern(t_data *data)
{
	t_fern_params	params;
	int				i;

	init_fern_params(&params, data);
	ft_memset(data->addr, 0, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	i = 0;
	while (i < 300000)
	{
		apply_fern_transform(&params);
		plot_fern_point(&params, data);
		i++;
	}
}
