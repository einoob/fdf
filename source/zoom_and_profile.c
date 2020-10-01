/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_profile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:49:34 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:44 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_array *start, t_array *end)
{
	start->x = (start->x - start->y) * cos(0.523599);
	end->x = (end->x - end->y) * cos(0.523599);
	start->y = -start->z + (start->x + start->y) * sin(0.523599);
	end->y = -end->z + (end->x + end->y) * sin(0.523599);
}

void	new_coords(t_info *info, int y, int x, int w)
{
	x += 0;
	while (y < info->height)
	{
		while (w < wordcount(info->raw_map[y]))
		{
			set_coords(info, y, w);
			w++;
		}
		y++;
		x = 0;
		w = 0;
	}
}

void	zoom(t_info *info, int action)
{
	if (action == 0)
	{
		info->depth *= 1.1;
		info->ratio *= 1.1;
	}
	else
	{
		info->depth *= 0.9;
		info->ratio *= 0.9;
	}
	new_coords(info, 0, 0, 0);
	mlx_clear_window(info->mlx, info->win);
	draw_stuff(info, 0, 0);
}

void	change_profile(t_info *info, int action)
{
	if (action == 1)
		info->depth--;
	else
		info->depth++;
	new_coords(info, 0, 0, 0);
	mlx_clear_window(info->mlx, info->win);
	draw_stuff(info, 0, 0);
}

void	change_projection(t_info *info, int angle)
{
	mlx_clear_window(info->mlx, info->win);
	if (angle == 1)
		info->projection = 1;
	else
		info->projection = 2;
	draw_stuff(info, 0, 0);
}
