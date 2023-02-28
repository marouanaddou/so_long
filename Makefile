NAME = so_long
CC = cc
RM = rm -rf
SRC = so_long.c libft.c checkmap.c checkvalidpath.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
%.o : %.c so_long.h 
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@$(RM) $(OBJ) 
fclean : clean
	@$(RM) $(NAME) 
re : fclean all
.PHONY : all fclean clean re 