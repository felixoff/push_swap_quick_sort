# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:27:08 by sjennett          #+#    #+#              #
#    Updated: 2021/03/08 19:32:16 by sjennett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIR) 
INCLUDES = -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_HEADERS = $(LIBFT_DIR)

HEADERS_LIST = push_swap.h
HEADERS_DIR = includes/
HEADERS = includes/push_swap.h

SOURCES_LIST_C = checker.c common1.c common2.c common3.c common4.c common0.c common5.c

SOURCES_DIR_C = srcs/
SOURCES_C = srcs/checker.c  srcs/common1.c srcs/common2.c srcs/common3.c srcs/common4.c srcs/common0.c srcs/common5.c

SOURCES_LIST_P = push.c push2.c push3.c common1.c common2.c common3.c common4.c common0.c common5.c

SOURCES_DIR_P = srcs/
SOURCES_P = srcs/push.c srcs/push2.c srcs/push3.c  srcs/common1.c srcs/common2.c srcs/common3.c srcs/common4.c srcs/common0.c srcs/common5.c


OBJECTS_LIST_C = $(patsubst %.c, %.o, $(SOURCES_LIST_C))
OBJECTS_DIR_C = objects_c/
OBJECTS_C = $(addprefix $(OBJECTS_DIR_C), $(OBJECTS_LIST_C))

OBJECTS_LIST_P = $(patsubst %.c, %.o, $(SOURCES_LIST_P))
OBJECTS_DIR_P = objects_p/
OBJECTS_P = $(addprefix $(OBJECTS_DIR_P), $(OBJECTS_LIST_P))



all: $(LIBFT)  $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJECTS_DIR_C) $(OBJECTS_C)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_C) $(LIBRARIES) -o $(NAME_C)
	@echo "$(NAME_C): $(NAME_C) was created" & echo

$(NAME_P): $(OBJECTS_DIR_P) $(OBJECTS_P)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_P)  $(LIBRARIES) -o $(NAME_P)
	@echo "$(NAME_P): $(NAME_P) was created" & echo

$(OBJECTS_DIR_C):
	@mkdir -p $(OBJECTS_DIR_C)

$(OBJECTS_DIR_P):
	@mkdir -p $(OBJECTS_DIR_P)

$(OBJECTS_DIR_C)%.o : $(SOURCES_DIR_C)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIR_P)%.o : $(SOURCES_DIR_P)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "$(LIBFT): Creating $(LIBFT)..."
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJECTS_DIR_C)
	@echo "$(NAME_C): object files were deleted"
	@rm -rf $(OBJECTS_DIR_P)
	@echo "$(NAME_P): object files were deleted"

fclean: clean
	@rm -f $(LIBFT)
	@echo "libft.a: $(LIBFT) was deleted"
	@rm -f $(NAME_C)
	@echo "$(NAME_C): $(NAME_C) was deleted"
	@rm -f $(NAME_P)
	@echo "$(NAME_P): $(NAME_P) was deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
