/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:01:42 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:34 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_depth_ratio(t_info *info)
{
	info->depth = 2.0000;
	info->ratio = 20.0000;
	info->projection = 1;
	info->center_x = 0;
	info->center_y = 0;
	window_size(info);
}

int		read_file(t_info *info, int fd, int y)
{
	char	*line;
	int		line_width;

	info->width = 0;
	line_width = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info->raw_map[y] = ft_strdup(line);
		line_width = wordcount(line);
		free(line);
		if (line_width > info->width)
			info->width = line_width;
		ft_putendl(info->raw_map[y]);
		y++;
	}
	info->raw_map[y] = NULL;
	if (!(validate_file(info, 0, 0)) && error_print(fd, 1))
		return (0);
	init_depth_ratio(info);
	if (!(get_coords(info, 0, 0, 0)))
		return (0);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->win_width,
	info->win_height, info->name);
	return (1);
}

void	line_count(t_info *info, int fd)
{
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	info->height = y;
	info->raw_map = (char**)malloc(sizeof(char*) * (y + 1));
}
