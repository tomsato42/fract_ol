/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:32:18 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 08:32:36 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	auto_zoom(t_data *data)
{
	if (!data->auto_zoom)
		return (0);
	if (data->zoom_direction > 0)
	{
		data->zoom *= (1.0 + ZOOM_SPEED);
		if (data->zoom >= MAX_ZOOM)
			data->zoom_direction = -1;
	}
	else
	{
		data->zoom *= (1.0 - ZOOM_SPEED);
		if (data->zoom <= MIN_ZOOM)
			data->zoom_direction = 1;
	}
	redraw(data);
	return (0);
}

void	toggle_auto_zoom(t_data *data)
{
	data->auto_zoom = !data->auto_zoom;
	if (data->auto_zoom)
		data->zoom_direction = 1;
}
