# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/09 11:28:14 by bmbarga           #+#    #+#              #
#    Updated: 2015/10/27 20:22:28 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c get_data.c lib_1.c check_errors.c fun_err_01.c \
	    init_1.c debug_1.c hash.c  get_data_tools.c get_data_tools2.c \
		lib_2.c pathfinder.c find_paths.c avoid_traffic_jams.c \
		correct_path.c correct_path_tools.c debug_2.c get_set.c \
		get_comb_set.c

LIBSRC = ft_memset.c ft_memalloc.c ft_memmove.c \
	 	 ft_strchr.c ft_strjoin.c ft_strsub.c ft_strcpy.c ft_strnew.c \
		 ft_memcpy.c ft_strcat.c ft_putnbr.c ft_atoi.c ft_isdigit.c \
		 ft_strsplit.c ft_strcmp.c ft_strncmp.c get_next_line.c

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:.c=.o)

SRCDIR = ./srcs/

OBJDIR = ./objs/

LIBSRCDIR = ./srcs/libft/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

LIBSRCS = $(addprefix $(LIBSRCDIR), $(LIBSRC))

LIBOBJS = $(addprefix $(OBJDIR), $(LIBOBJ))

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBOBJS)

$(OBJS): $(SRCS) $(LIBSRCS)
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS) $(LIBSRCS)
	mv $(OBJ) $(LIBOBJ) $(OBJDIR) 

clean:
	rm -rf $(OBJS) $(LIBOBJS)
	rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
