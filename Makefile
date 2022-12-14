# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:46:08 by cmilagro          #+#    #+#              #
#    Updated: 2022/03/10 13:46:15 by cmilagro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

GREEN 				=	\033[0;32m
RED					=	\033[0;31m
RESET				=	\033[0m

CC					=	gcc
SANITAZE			=	-fsanitize=address
FLAGS				=	-Wall -Wextra -Werror
INCLUDES			=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	./libft/
LIBFT_HEADERS		=	$(LIBFT_DIR)includes/


HEADERS_LIST		=	push_swap.h
HEADERS_DIR			=	./includes/
HEADERS				=	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR			=	sources/
SOURCES_LIST		=	main.c					\
						finder.c				\
						check.c					\
						full_sort.c				\
						other_utils.c			\
						qick_sort.c				\
						stack_manipulations.c	\
						utils_rot_push_swap.c	\
						utils_rot_rot.c

SOURCES				=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST))


OBJECTS_DIR			=	objects/
OBJECTS_LIST		=	$(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all					:	$(NAME)

$(NAME)				:	$(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
					@$(CC) $(FLAGS) $(LIBFT) $(INCLUDES) $(OBJECTS) -o $(NAME)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIR)		:
					@mkdir -p $(OBJECTS_DIR)
					@echo "$(NAME): $(GREEN)$(OBJECTS_DIR) was created$(RESET)"

$(OBJECTS_DIR)%.o	: $(SOURCES_DIR)%.c $(HEADERS)
					@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
					@echo "$(GREEN)*$(RESET)\c"


$(LIBFT)			:
					@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
					@$(MAKE) -sC $(LIBFT_DIR)

clean				:
					@$(MAKE) -sC $(LIBFT_DIR) clean
					@rm -rf $(OBJECTS_DIR)
					@echo "$(NAME): $(RED)$(OBJECTS_DIR) was deleted$(RESET)"
					@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean				: clean
					@rm -f $(LIBFT)
					@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
					@rm -f $(NAME)
					@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re					:
					@$(MAKE) fclean
					@$(MAKE) all

.PHONY				:	all clean fclean re