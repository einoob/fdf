/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:50:04 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:28 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_map(t_info *info)
{
	init_depth_ratio(info);
	new_coords(info, 0, 0, 0);
	mlx_clear_window(info->mlx, info->win);
	draw_stuff(info, 0, 0);
}

void	move_upways(t_info *info, float key, int y, int w)
{
	if (key == 125)
	{
		key = 1;
		info->center_y++;
	}
	else if (key == 126)
	{
		key = -1;
		info->center_y--;
	}
	while (y < info->height)
	{
		while (w < wordcount(info->raw_map[y]))
		{
			info->arr[y][w]->y += key;
			if (info->projection == 2)
				info->arr[y][w]->x += key;
			w++;
		}
		y++;
		w = 0;
	}
	mlx_clear_window(info->mlx, info->win);
	draw_stuff(info, 0, 0);
}

void	move_sideways(t_info *info, float key, int y, int w)
{
	if (key == 123)
	{
		key = -1;
		info->center_x--;
	}
	else if (key == 124)
	{
		key = 1;
		info->center_x++;
	}
	while (y < info->height)
	{
		while (w < wordcount(info->raw_map[y]))
		{
			info->arr[y][w]->x += key;
			if (info->projection == ISOMETRIC)
				info->arr[y][w]->y -= key * 4.75;
			w++;
		}
		y++;
		w = 0;
	}
	mlx_clear_window(info->mlx, info->win);
	draw_stuff(info, 0, 0);
}
