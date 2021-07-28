##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## Makefile
##

SRC		=	src/main.c						\
			src/window.c					\
			src/menu/create_menu.c			\
			src/menu/create_sprite_menu.c	\
			src/menu/menu.c					\
			src/menu/animate_button.c		\
			src/menu/howto.c				\
			src/menu/options.c				\
			src/menu/lose.c					\
			src/menu/create_menu_opt.c		\
			src/create.c					\
			src/game/play_game.c			\
			src/game/cursor.c				\
			src/game/pause.c				\
			src/game/opt_pause.c			\
			src/map/draw_map.c				\
			src/map/load_from_file.c		\
			src/map/find_positions.c 		\
			src/map/do_collisions.c 		\
			src/map/do_collisions_game.c	\
			src/map/map.c					\
			src/map/endd_map.c 				\
			src/map/do_zoom.c 				\
			src/map/do_collisions_end.c 	\
			src/map/tower.c 				\
			src/player/player_idle.c		\
			src/player/player_run.c			\
			src/player/player_animation.c	\
			src/player/create_player.c		\
			src/player/check_hitbox.c		\
			src/player/check_move.c			\
			src/player/create_king.c		\
			src/player/create_pnj.c			\
			src/player/display_pnj.c		\
			src/enemy/create_enemy.c		\
			src/enemy/enemy_animation.c		\
			src/enemy/init_enemy.c			\
			src/enemy/move_enemy.c			\
			src/enemy/manage_boss.c			\
			src/enemy/display_enemy.c		\
			src/enemy/enemy_mage.c			\
			src/inventory/draw_inv.c		\
			src/inventory/inventory.c		\
			src/inventory/load_inv.c		\
			src/inventory/init_items.c		\
			src/inventory/manage_items.c		\
			src/inventory/main_inventory.c		\
			src/weapon/create_swords.c		\
			src/weapon/animate_swords.c		\
			src/weapon/display_swords.c		\
			src/stats/add_stats.c			\
			src/stats/create_stats_box.c	\
			src/stats/stats.c

OBJ		=	$(SRC:.c=.o)

NAME		=	my_rpg

LDFLAGS 	=	-L lib/my -l my -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

CPPFLAGS	= 	-I include/

CFLAGS		=	-g3 -W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) re -C lib/my
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(CSFML)

clean:
	$(RM) $(OBJ)
	$(RM) lib/my/*.o
	$(RM) src/*.o
	$(RM) *~
	$(RM) lib/libmy.a
	$(RM) lib/my/libmy.a

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
