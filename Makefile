# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 14:49:52 by hahmed            #+#    #+#              #
#    Updated: 2018/11/09 23:08:31 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_FILES = ft_printf.c \
	  		parse.c \
	  		cast_length.c \
	  		string.c \
	  		format.c \
	  		handle_d.c \
	  		handle_u.c \
	  		handle_o.c \
	  		handle_x.c \
	  		handle_p.c \
	  		handle_c.c \
	  		handle_wc.c \
	  		handle_s.c \
	  		handle_ws.c \
	  		handle_percent.c \
	  		handle_invalid.c \
	  		print_with_padding.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = src/

OBJ_DIR = obj/

INC = inc/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME):
	make -C libft/
	mv libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ_FILES) $(OBJ_DIR)
	ar -rcs $(NAME) $(OBJ)

clean:
	make clean -C libft/
	$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
