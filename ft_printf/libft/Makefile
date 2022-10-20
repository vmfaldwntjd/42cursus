# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 09:39:13 by ajordan-          #+#    #+#              #
#    Updated: 2022/08/26 18:38:29 by jchin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INCLUDES	=	../include
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

SRC_FILES =	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
			ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c\
			ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
			ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
			
OBJ_FILES = $(SRC_FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			$(AR) $(NAME) $(OBJ_FILES)

%.o : %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) -rf $(OBJ_FILES)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
