NAME	=	fdf

FLAGS	=	-Wall -Werror -Wextra 

GCC		=	gcc -o

HH		=	fdf.h

LINK	=  -lmlx -framework OpenGL -framework AppKit

SRCS	=	ft_fdf.c \
			ft_count.c \
			ft_draw_pixel.c \
			ft_ut1.c \
			ft_ut2.c \
			ft_ut3.c \
			GNL/get_next_line.c \
			GNL/get_next_line_utils.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		$(GCC) $(NAME) $(FLAGS) $(OBJS) $(LINK) ./libft/libft.a minilibx_macos/libmlx.a

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: clean all
