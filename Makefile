# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/03/03 13:07:29 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		= ft_ls
_SRC		= 	ft_get/ft_get_max.c\
				ft_get/ft_get_max_2.c\
				ft_get/ft_get_info.c\
				ft_get/ft_get_time.c\
				ft_show/ft_print.c\
				ft_show/ft_show.c\
				ft_show/ft_show_long.c\
				ft_show/ft_exit.c\
				ft_utils/ft_align.c\
				ft_utils/ft_parser.c\
				ft_utils/ft_reject_dot.c\
				ft_utils/ft_sort.c\
				ft_utils/ft_utils.c\
				ft_utils/ft_init.c\
				ft_utils/ft_iter.c\
				ft_compute.c\
				ft_ls.c
				
SRC			= $(addprefix srcs/,$(_SRC))
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= -Llibft -lft -Ilibft

all: $(NAME)

$(NAME):
	@mkdir bin
	@make -C libft
	@gcc $(CFLAGS) $(SRC) -Iincludes -o $(NAME) $(LIBFT)
	@echo $(NAME)" compiled"

clean:
	@make clean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o files"

fclean:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all

.PHONY: all, clean, fclean, re
