/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:36:43 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:21 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	define_color(t_info *info, t_array *start, t_array *end)
{
	float	div;
	int		color;

	color = 0X0026E6;
	div = fabs(info->depth);
	if (start->color == 0 && end->color == 0)
	{
		if (fabs(start->z) / div > 14.1 || fabs(end->z) / div > 14.1)
			color = 0XEEEEEE;
		else if (fabs(start->z) / div > 11.1 || fabs(end->z) / div > 11.1)
			color = 0XDDDDDD;
		else if (fabs(start->z) / div > 5.1 || fabs(end->z) / div > 5.1)
			color = 0XCC6600;
		else if (fabs(start->z) / div > 3.1 || fabs(end->z) / div > 3.1)
			color = 0XFFE666;
		else if (fabs(start->z) / div > 0.0 || fabs(end->z) / div > 0.0)
			color = 0X009900;
		start->color = color;
		end->color = color;
	}
	else if (start->color != 0)
		end->color = start->color;
	else if (end->color != 0)
		start->color = end->color;
}

void	draw_horizontal(t_info *info, t_array start, t_array end, int incre_y)
{
	float	delta_x;
	float	delta_y;
	float	danny;

	if (start.x > end.x)
		float_swap_x2(&start.y, &end.y, &start.x, &end.x);
	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	if (delta_y < 0)
		incre_y = -1;
	if (delta_y < 0)
		delta_y *= -1;
	danny = 2 * delta_y - delta_x;
	while (start.x < end.x)
	{
		define_color(info, &start, &end);
		mlx_pixel_put(info->mlx, info->win, start.x + info->win_width / 2,
		start.y + info->win_height / 2, start.color);
		if (danny > 0)
			start.y += incre_y;
		if (danny > 0)
			danny -= 2 * delta_x;
		danny += 2 * delta_y;
		start.x++;
	}
}

void	draw_vertical(t_info *info, t_array start, t_array end, int incre_x)
{
	float	delta_x;
	float	delta_y;
	float	danny;

	if (start.y > end.y)
		float_swap_x2(&start.x, &end.x, &start.y, &end.y);
	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	if (delta_x < 0)
		incre_x = -1;
	if (delta_x < 0)
		delta_x *= -1;
	danny = 2 * delta_x - delta_y;
	while (start.y <= end.y)
	{
		define_color(info, &start, &end);
		mlx_pixel_put(info->mlx, info->win, start.x + info->win_width / 2,
		start.y + info->win_height / 2, start.color);
		if (danny > 0)
			start.x += incre_x;
		if (danny > 0)
			danny -= 2 * delta_y;
		danny += 2 * delta_x;
		start.y++;
	}
}

void	draw_line(t_info *info, t_array start, t_array end, int projection)
{
	count_starting_point(info, &start, &end);
	if (projection == ISOMETRIC)
		isometric(&start, &end);
	if (fabs(end.y - start.y) < fabs(end.x - start.x))
	{
		draw_horizontal(info, start, end, 1);
		return ;
	}
	else
		draw_vertical(info, start, end, 1);
}

void	draw_stuff(t_info *info, int x, int y)
{
	int		next_x;
	int		next_y;

	while (y < info->height)
	{
		while (x < wordcount(info->raw_map[y]))
		{
			next_x = x + 1;
			next_y = y + 1;
			if (x + 1 < wordcount(info->raw_map[y]))
				draw_line(info, *(info->arr[y][x]), *(info->arr[y][next_x]),
				info->projection);
			while (y + 1 < info->height && x >= wordcount(info->raw_map[next_y])
			&& wordcount(info->raw_map[y]) > wordcount(info->raw_map[next_y]))
				next_y++;
			if (y + 1 < info->height)
				draw_line(info, *(info->arr[y][x]), *(info->arr[next_y][x]),
				info->projection);
			x++;
		}
		y++;
		x = 0;
	}
	write_instructions(info);
}
