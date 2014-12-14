# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/09 11:28:14 by bmbarga           #+#    #+#              #
#    Updated: 2014/12/14 03:51:09 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c get_data.c lib1.c check_errors.c fun_err_01.c \
	  get_next_line.c ft_memset.c ft_memalloc.c ft_memmove.c \
	  ft_strchr.c ft_strjoin.c ft_strsub.c ft_strcpy.c ft_strnew.c \
	  ft_memcpy.c ft_strcat.c ft_strlen.c

OBJ = $(SRC:.c=.o)

SRCDIR = ./srcs/

OBJDIR= ./objs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	mv $(OBJ) $(OBJDIR) 

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
