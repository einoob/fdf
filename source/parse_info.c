/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:23:52 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:30 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		is_number(char c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

void	set_coords(t_info *info, int y, int w)
{
	info->depth = fabs(info->depth) < 0.5 ? 0.5 : info->depth;
	info->ratio = fabs(info->ratio) < 5 ? 5 : info->ratio;
	info->arr[y][w]->z = info->arr[y][w]->static_z * info->depth;
	if (info->center_x == CENTER && info->center_y == CENTER)
	{
		info->arr[y][w]->x = w;
		info->arr[y][w]->y = y;
	}
}

int		first_coords(t_info *info, int y, int x, int w)
{
	if (!(info->arr[y] =
	(t_array**)malloc(sizeof(t_array*) * (info->width + 1))))
		return (0);
	while (info->raw_map[y][x] != '\0')
	{
		if (!(info->arr[y][w] = (t_array*)malloc(sizeof(t_array))))
			return (0);
		while (info->raw_map[y][x] == ' ')
			x++;
		if (is_number(info->raw_map[y][x]))
		{
			info->arr[y][w]->color = 0;
			info->arr[y][w]->static_z = (float)ft_atoi(&(info->raw_map[y][x]));
			set_coords(info, y, w);
		}
		while (is_number(info->raw_map[y][x]))
			x++;
		if (info->raw_map[y][x] == ',')
			info->arr[y][w]->color = atoi_base(&(info->raw_map[y][x + 3]));
		while (info->raw_map[y][x] != ' ' && info->raw_map[y][x] != '\0')
			x++;
		w++;
	}
	info->arr[y][w] = NULL;
	return (1);
}

int		get_coords(t_info *info, int y, int x, int w)
{
	if (!(info->arr =
	(t_array***)malloc(sizeof(t_array**) * (info->height + 1))))
		return (0);
	while (info->raw_map[y] != NULL)
	{
		if (!(first_coords(info, y, 0, 0)))
			return (0);
		y++;
		x = 0;
		w = 0;
	}
	info->arr[y] = NULL;
	return (1);
}
