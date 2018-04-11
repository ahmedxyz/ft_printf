# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 14:49:52 by hahmed            #+#    #+#              #
#    Updated: 2018/04/11 01:16:51 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INC = ft_printf.h

SRC = ft_printf.c ft_check.c print_invalid.c print_percent.c print_d.c \
	  print_u.c print_o.c print_x.c print_p.c print_c.c print_s.c get_length.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	mv libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	ar -rcs $(NAME) $(OBJ)

# DELETE
test:
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) $(INC) libft/*.a main.c
	mv a.out test0
# DELETE

clean:
	make clean -C libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
