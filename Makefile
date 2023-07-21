NAME = cub3d

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = cub3d.c helps.c helps2.c get_next_line.c get_next_line_utils.c parce_map.c parce_map2.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	 gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all