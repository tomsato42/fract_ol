/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hundle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:17:52 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 09:00:43 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	clean_exit(data);
	return (0);
}

int	animate_colors(t_data *data)
{
	if (data->animate_colors)
	{
		data->color_shift += COLOR_SHIFT_SPEED;
		if (data->color_shift >= 360)
			data->color_shift = 0;
		redraw(data);
	}
	return (0);
}

void	clean_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}
