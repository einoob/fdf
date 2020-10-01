# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 13:26:48 by elindber          #+#    #+#              #
#    Updated: 2020/10/01 15:46:48 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = source/control_management.c source/draw_lines.c source/main.c \
	  source/move_and_reset.c source/parse_info.c source/read_file.c \
	  source/utils.c source/window_define.c source/zoom_and_profile.c

FLAGS = -Wall -Werror -Wextra -O3

MLXFL = -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libftprintf/

all: $(NAME)

$(NAME):
	@ make -C libftprintf/ fclean && make -C libftprintf/
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(MLXFL) -L $(LIBFT) -lftprintf
	@ echo "fdf ready"

clean:
#	@ /bin/rm -f *.o
	@ make -C libftprintf/ clean
	@ echo "object files cleaned"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C libftprintf/ fclean
	@ echo "fdf removed"
	
re: fclean all

run: clean
	./fdf test_maps/42.fdf

pyr: clean
	./fdf test_maps/pyramide.fdf

test: clean
	./fdf test_maps/tester.fdf

elem: clean
	./fdf test_maps/elem.fdf

pyl: clean
	./fdf test_maps/pylone.fdf
