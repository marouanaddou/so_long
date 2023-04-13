NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
SRC = so_long.c libft.c checkmap.c checkvalidpath.c so_long_utils.c \
		move_player.c so_long_utils1.c so_long_free.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $@
%.o : %.c so_long.h 
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all
.PHONY : all fclean clean re 