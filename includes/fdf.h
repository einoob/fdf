/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:46:45 by elindber          #+#    #+#             */
/*   Updated: 2020/10/01 15:46:09 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"
# define ISOMETRIC 2
# define CENTER 0

typedef struct	s_array
{
	float		x;
	float		y;
	float		z;
	float		static_z;
	int			color;
}				t_array;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	char		**raw_map;
	char		*name;
	int			height;
	int			width;
	int			win_height;
	int			win_width;
	int			projection;
	int			center_x;
	int			center_y;
	float		depth;
	float		ratio;
	t_array		***arr;
}				t_info;

void			line_count(t_info *info, int fd);
void			draw_stuff(t_info *info, int x, int y);
void			write_instructions(t_info *info);
void			draw_line
				(t_info *info, t_array start, t_array end, int projection);
void			draw_horizontal
				(t_info *info, t_array start, t_array end, int incre_y);
void			float_swap_x2(float *a, float *b, float *c, float *d);
void			init_depth_ratio(t_info *info);
void			window_size(t_info *info);
void			count_starting_point
				(t_info *info, t_array *start, t_array *end);
void			zoom(t_info *info, int action);
void			change_projection(t_info *info, int angle);
void			change_profile(t_info *info, int action);
void			move_sideways(t_info *info, float key, int y, int w);
void			move_upways(t_info *info, float key, int y, int w);
void			isometric(t_array *start, t_array *end);
void			reset_map(t_info *info);
void			set_coords(t_info *info, int y, int w);
void			new_coords(t_info *info, int y, int x, int w);
int				error_print(int fd, int error);
int				read_file(t_info *info, int fd, int y);
int				key_press(int key, void *param);
int				get_coords(t_info *info, int y, int x, int w);
int				validate_file(t_info *info, int y, int x);
int				is_number(char c);
int				wordcount(char *str);
int				nbrcount(float nbr);
int				atoi_base(char *str);

#endif
