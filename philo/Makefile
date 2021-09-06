# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 20:37:01 by rcabezas          #+#    #+#              #
#    Updated: 2021/09/06 15:27:18 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_PH = philo.c error.c ft.c actions.c time.c

SRCS_DIR = srcs/

INCLUDES = includes/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_PH))

OBJS = $(SRCS:.c=.o)

RM = rm -rf

CFLAGS = gcc -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJS)
	@$(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean:			clean
	@$(RM) $(NAME)

re:				fclean all

.PHONY: 		all fclean clean re
