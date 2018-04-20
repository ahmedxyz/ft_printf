# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 14:49:52 by hahmed            #+#    #+#              #
#    Updated: 2018/04/20 04:03:00 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INC = ft_printf.h

SRC = ft_printf.c \
	  parse.c \
	  cast_length.c \
	  string.c \
	  format.c \
	  print_d.c \
	  print_u.c \
	  print_o.c \
	  print_x.c \
	  print_p.c \
	  print_c.c \
	  print_wc.c \
	  print_s.c \
	  print_ws.c \
	  print_percent.c \
	  print_invalid.c \
	  print_with_padding.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	mv libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	ar -rcs $(NAME) $(OBJ)

clean:
	make clean -C libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
