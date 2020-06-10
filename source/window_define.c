/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:05:25 by elindber          #+#    #+#             */
/*   Updated: 2020/02/28 15:58:07 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	window_size(t_info *info)
{
	int		r;

	r = info->ratio;
	info->win_width = info->width * r * 5 > 2560 ? 2560 : info->width * r * 5;
	info->win_height = info->height * r * 5 > 1314 ?
	1314 : info->height * r * 5;
}

void	count_starting_point(t_info *info, t_array *start, t_array *end)
{
	int		r;

	r = info->ratio;
	start->x = start->x * r - info->width * r / 2;
	end->x = end->x * r - info->width * r / 2;
	start->y = start->y * r - info->height * r / 2;
	end->y = end->y * r - info->height * r / 2;
}
