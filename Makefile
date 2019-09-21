NAME 		= doom
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -MMD -O3 -g #-fsanitize=address

ID_UN 		= $(shell id -un)
SRC_PATH 	= srcs/
OBJ_PATH 	= objs/
INC_PATH	= includes/ \
			  libft/includes/
LIBFT 		= libft/

WHITE       = "\\033[0m"
CYAN        = "\\033[36m"
GREEN       = "\\033[32m"

SRC_NAME = main.c \
			get_map.c \
			get_map2.c \
			init_data.c \
			init_data2.c \
			init_data3.c \
			get_event.c \
			get_event2.c \
			handle_events.c \
			handle_movement.c \
			color.c \
			raycast.c \
			rc_doomcalc.c \
			minimap.c \
			minimap2.c \
			set_infos.c \
			set_infos2.c \
			set_interface.c \
			utils.c \
			highlvl_graphics.c \
			lowlvl_graphics.c \
			exit.c \
			editor.c \
			init_editor.c \
			init_editor2.c \
			render.c \
			render2.c \
			tga_reader_data.c \
			tga_reader_fill_data.c \
			tga_reader_createpxl.c \
			tga_reader_uncompress.c \
			tga_reader_rot.c \
			tga_reader_main.c \
			get_sprite.c \
			get_sprite2.c \
			get_event_editor.c \
			free_all.c \
			free_all2.c \
			free_all3.c \
			free_all4.c \
			files.c  

OBJ_NAME = $(SRC_NAME:.c=.o)

LSDL2 	 	= -L ~/.brew/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lSDL2_gfx
ISDL2		= -I ~/.brew/include/ -D_THREAD_SAFE

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
DPD = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.d))

all: $(NAME)

$(NAME): $(OBJ)
	@Make -C $(LIBFT)
	@printf "$(CYAN)[WAIT]$(WHITE) Compiling into %-50s\r" $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) -o $(NAME) -L $(LIBFT) -lft $(LSDL2) $(INC) $(ISDL2) 
	@printf "$(GREEN)[OK]$(WHITE) %s has been well compiled\n" $(NAME)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	@printf "$(CYAN)[WAIT]$(WHITE) Compiling into .o %-50s\r" $@
	@$(CC) $(CFLAGS) $(INC) $(ISDL2) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@printf "$(GREEN)[OK]$(WHITE) Clean done\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@printf "$(GREEN)[OK]$(WHITE) Fclean done\n"

re: fclean all

.PHONY: all re clean fclean
-include $(DPD)
