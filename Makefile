# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 15:40:19 by rodcaeta          #+#    #+#              #
#    Updated: 2025/12/17 15:40:19 by rodcaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#LIBRARY NAME:
NAME = libftprintf.a

#FILES TO COMPILE:
FILES = ft_printf.c ft_printf_functions.c
OBJS = $(patsubst %.c, %.o, $(FILES))

# HEADER
HEADER = ft_printf.h

# COMPILING FLAGS:
CC = cc
FLAGS = -Wall -Werror -Wextra -I.

# REMOVE
RM = rm -f

#COLLORS ANSI:
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[5;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Deleted all your Objects files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RESET)"
	@echo			⠀⠀⠀⠀⠀⠀⠀"⢀⣠⣤⣶⣶⣶⣶⣶⣤⣄⡀"⠀⠀⠀⠀⠀⠀⠀⠀⠀
	@echo		⠀⠀⠀⠀⠀	"⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀"⠀⠀⠀⠀⠀
	@echo		⠀⠀⠀"⣠⣴⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣵⣄"⠀⠀⠀
	@echo		⠀⠀"⢾⣻⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⡀"⠀
	@echo		⠀"⠸⣽⣻⠃⣿⡿⠋⣉⠛⣿⣿⣿⣿⣿⣿⣿⣿⣏⡟⠉⡉⢻⣿⡌⣿⣳⡥"⠀
	@echo		⠀"⢜⣳⡟⢸⣿⣷⣄⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣤⣠⣼⣿⣇⢸⢧⢣"⠀
	@echo		⠀"⠨⢳⠇⣸⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀⡟⢆"⠀
	@echo		⠀⠀"⠈⠀⣾⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣽⣿⣿⠐⠈"⠀⠀
	@echo		⠀"⢀⣀⣼⣷⣭⣛⣯⡝⠿⢿⣛⣋⣤⣤⣀⣉⣛⣻⡿⢟⣵⣟⣯⣶⣿⣄⡀"⠀
	@echo		"⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣾⣶⣶⣴⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣧"
	@echo		"⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⡿"

re: fclean all

.PHONY: all clean fclean re
