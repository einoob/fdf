/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:06:14 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:19 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_instructions(t_info *info)
{
	int		color;

	color = 0XCCFFCC;
	mlx_string_put(info->mlx, info->win, 10, 10, color,
	"[1] and [2]changes projection");
	mlx_string_put(info->mlx, info->win, 10, 30, color,
	"[Q] and [W] changes profile");
	mlx_string_put(info->mlx, info->win, 10, 50, color,
	"[+] zooms in and [-] zooms out");
	mlx_string_put(info->mlx, info->win, 10, 70, color, "Arrow keys to move");
	mlx_string_put(info->mlx, info->win, 10, 90, color, "[R] resets");
	mlx_string_put(info->mlx, info->win, 10, 110, color, "[Esc] exits");
}

int		key_press(int key, void *param)
{
	t_info *info;

	info = param;
	if (key == 24)
		zoom(info, 0);
	if (key == 27)
		zoom(info, 1);
	if (key == 18)
		change_projection(info, 1);
	if (key == 19)
		change_projection(info, 2);
	if (key == 12)
		change_profile(info, 1);
	if (key == 13)
		change_profile(info, 2);
	if (key == 15)
		reset_map(info);
	if (key == 123 || key == 124)
		move_sideways(info, key, 0, 0);
	if (key == 125 || key == 126)
		move_upways(info, key, 0, 0);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
