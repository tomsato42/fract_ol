/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hundle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:17:52 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 08:39:54 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
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
