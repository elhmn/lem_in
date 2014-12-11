# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/09 11:28:14 by bmbarga           #+#    #+#              #
#    Updated: 2014/12/11 18:34:51 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c

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
