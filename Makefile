# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 11:56:39 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2020/01/29 16:15:14 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRC_PATH = sources
SRC_NAME = 	nseo/check_n_s_e_o.c 	\
			nseo/check_ne.c 		\
			nseo/check_nw.c 		\
			nseo/check_se.c 		\
			nseo/check_sw.c 		\
			algo.c 					\
			main.c 					\
			map.c 					\
			parsing.c
SRC_SUP = nseo
OBJ_PATH = .objects
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -L libft
LDLIBS = libft/libft.a 
MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL 	\
		-framework AppKit
OPTI_FLAGS = -O3 -march=native -flto -ffast-math
NAME = wolf3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ERASE = \033[2K\r
BLUE = \033[36m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
END = \033[0m

.PHONY: all, clean, fclean, re

all: lib $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) $(MINILIBX) $(OPTI_FLAGS) $(LDLIBS) $^ -o $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

lib:
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c libft/libft.a includes/wolf3d.h includes/keys.h includes/struct.h
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH)
