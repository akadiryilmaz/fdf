SRCS			= fdf.c rotate.c control_map.c draw.c utils/get_next_line.c utils/get_next_line_utils.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_split.c utils/ft_atoi.c utils/ft_printf.c utils/ft_itoa.c
RM				= rm -f
GCC				= gcc
NAME			= fdf

all:			$(SRCS) $(NAME)


$(NAME): $(SRCS)
	@make -C mlx
	@$(GCC) -I./mlx -framework OpenGL -framework AppKit $(SRCS) -L./mlx -lmlx -o $(NAME)
	@echo mlx is compiled successfully
	@echo fdf is created successfully
clean:
	@$(RM) $(NAME)
	@echo fdf is removed successfully

fclean:			clean
	@make clean -C mlx

re:				fclean
	make


.PHONY:			all clean fclean re
