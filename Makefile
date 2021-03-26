# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 13:58:49 by ahaddad           #+#    #+#              #
#    Updated: 2020/12/02 19:33:55 by ahaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB = libcub3d.a

MAIN = cub3d.c

FILES = $(wildcard ./SRCs/tools.c ./SRCs/save.c ./SRCs/utils3.c ./SRCs/check.c ./SRCs/utils2.c ./SRCs/pars_text.c ./SRCs/sort_sprt.c ./SRCs/pars_map.c ./SRCs/pars.c ./SRCs/pars1.c ./srcs/utils.c ./SRCs/calc_direction.c ./SRCs/floor.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./SRCs/handle_key_press.c ./SRCs/handle_sprites.c ./SRCs/raycasting.c ./SRCs/start_game.c)

#FILES_B = $(wildcard ./CUB3D_bonus/SRCs/*.c)

HEADER = cub.h

OBJECT = $(FILES:.c=.o)

#OBJECT_B = $(FILES_B:.c=.o)

#LIBFT 			= libft

FLAGS = -Wextra -Werror -Wall

#LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c

all: $(NAME) 

$(NAME): $(OBJECT) $(HEADER)
	@mv *.o ./SRCs
	@ar -rcs $(LIB) $(OBJECT)
	@gcc  $(FLAGS) $(MAIN) $(LIB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "[Done !]"
# LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c 

# bonus:

# $(NAME): $(OBJECT_B) $(HEADER)
# 	@mv *.o ./CUB3D_bonus/SRCs
# 	@ar -rcs $(LIB) $(OBJECT_B)
# 	@gcc  $(FLAGS) $(MAIN) $(LIB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# 	@echo "\n\033[36m***** YOU MAY START YOUR GAME NOW ***** \033[0m\n"

%.o:%.c $(HEADER)
	@gcc -c $< $(FLAGS)

clean:
	@rm -rf srcs/*.o $(LIB)

fclean: clean
	@rm -rf $(NAME)

re : fclean all
