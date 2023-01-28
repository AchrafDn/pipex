# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adadoun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 06:31:21 by adadoun           #+#    #+#              #
#    Updated: 2023/01/25 06:31:25 by adadoun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
Cflags = -Wall -Wextra -Werror -fsanitize=address -g3
Cfiles = pipex.c child.c ft_split.c ft_strjoin.c ft_strncmp.c ft_utils.c

OBJ = ${Cfiles:.c=.o}

RM = rm -f
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(Cflags) $(OBJ) -o $(NAME)

${OBJ} :  $(Cfiles)

.c.o:
	$(CC) $(Cflags) -c $< -o $@
	
clean :
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
