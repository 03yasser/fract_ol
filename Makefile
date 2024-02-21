MANDATORY = main.c fract_ol_utils1.c math_utils.c fract_ol_utils2.c
Bonus = fract_ol_utils1_bonus.c fract_ol_utils2_bonus.c main_bonus.c math_utils_bonus.c
M_srcs = $(addprefix Mandatory/,$(MANDATORY))
B_srcs = $(addprefix Bonus/,$(Bonus)) 
M_OBJ = $(M_srcs:.c=.o)
B_OBJ = $(B_srcs:.c=.o)
NAME = fractol
NAME_BONUS = fractol_bonus
CFLAGS = -Wall -Wextra -Werror -O3
all: $(NAME)

$(NAME): $(M_OBJ)
	cc $(CFLAGS) $(M_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus:$(NAME_BONUS)
	cc $(CFLAGS) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
$(NAME_BONUS):$(B_OBJ)
Mandatory/%.o: Mandatory/%.c Mandatory/fract_ol.h
	cc $(CFLAGS) -I. -Imlx -c $< -o $@
Bonus/%.o:Bonus/%.c Bonus/fract_ol_bonus.h
	cc $(CFLAGS) -I. -Imlx -c $< -o $@
clean : 
	rm -rf $(M_OBJ) $(B_OBJ)
fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
re : fclean all
