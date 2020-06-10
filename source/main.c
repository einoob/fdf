/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:46:16 by elindber          #+#    #+#             */
/*   Updated: 2020/03/09 14:57:02 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		error_print(int fd, int error)
{
	if (error == 1)
	{
		ft_printf("Error: Not a valid file.\n");
		close(fd);
	}
	if (error == 2)
	{
		ft_printf("Error: Open unsuccesful.\n");
		close(fd);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_info	*info;
	int		fd;

	if (ac != 2)
	{
		ft_printf("usage: ./fdf [file]\n");
		return (0);
	}
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	info->name = ft_strdup(av[1]);
	if (!(fd = open(av[1], O_RDONLY)) && error_print(fd, 2))
		return (-1);
	line_count(info, fd);
	close(fd);
	if (!(fd = open(av[1], O_RDONLY)) && error_print(fd, 2))
		return (-1);
	if (!(read_file(info, fd, 0)))
		return (-1);
	close(fd);
	draw_stuff(info, 0, 0);
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_loop(info->mlx);
	return (0);
}
