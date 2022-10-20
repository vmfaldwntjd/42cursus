# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchin <jchin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:51:37 by ajordan-          #+#    #+#              #
#    Updated: 2022/08/27 11:35:32 by jchin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

SRC_FILES	=	ft_printf.c tools.c ft_print_ptr.c ft_print_unsigned_int.c ft_print_hex.c
OBJS = $(SRC_FILES:.c=.o)

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(OBJS))

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
