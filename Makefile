# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 21:52:42 by asokolov          #+#    #+#              #
#    Updated: 2022/08/21 13:23:09 by asokolov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread

CC = gcc

SRC =	main.c				\
		error.c				\
		init.c				\
		init_helpers.c		\
		create_threads.c	\
		time.c				\
		fork_algorithm.c	\
		actions.c			\
		write.c				\
		about_death.c		\
		join_destroy_free.c	\
		other_fonctions.c

OBJS = ${SRC:.c=.o}

DEPENDENCES = ${OBJS:.o=.d}

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	${OBJS}
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(COLOUR)PHILO : MAKE OBJS$(COLOUR_END)"
	
all: $(NAME)

clean: 
	@rm -f $(OBJS)
	@echo "$(COLOUR)PHILO : rm -f OBJS$(COLOUR_END)"
	@rm -f $(DEPENDENCES)
	@echo "$(COLOUR)PHILO : rm -f DEPENDENCES$(COLOUR_END)"

fclean:
	@rm -f $(OBJS)
	@echo "$(COLOUR)PHILO : rm -f OBJS$(COLOUR_END)"
	@rm -f $(DEPENDENCES)
	@echo "$(COLOUR)PHILO : rm -f DEPENDENCES$(COLOUR_END)"
	@rm -f $(NAME)
	@echo "$(COLOUR)PHILO : rm -f philo$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re

COLOUR=\033[0;34m
COLOUR_END=\033[0;34m