/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:13:12 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:37 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_character(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')
	|| (c >= 'a' && c <= 'f') || c == ' ' || c == ',' || c == 'x'
	|| c == 'X' || c == '-');
}

int		validate_file(t_info *info, int y, int x)
{
	if (info->width == 0 || info->height == 0)
		return (0);
	while (y < info->height)
	{
		while (info->raw_map[y][x] != '\0')
		{
			if (!(check_character(info->raw_map[y][x])))
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

void	float_swap_x2(float *a, float *b, float *c, float *d)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

int		wordcount(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!str)
		return (c);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			c++;
		i++;
	}
	return (c);
}

int		atoi_base(char *str)
{
	int		i;
	int		res;
	int		check;

	i = 0;
	res = 0;
	check = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')
	|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		res *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		i++;
		check++;
	}
	if (check != 6)
		return (0);
	return (res);
}
