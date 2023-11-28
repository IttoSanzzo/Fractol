# **************************************************************************** #
#									       #
#							  :::	   ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#						      +:+ +:+	      +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	       #
#						  +#+#+#+#+#+	+#+	       #
#    Created: 2023/11/26 19:20:16 by marcosv2	       #+#    #+#	       #
#    Updated: 2023/11/28 12:28:50 by marcosv2         ###   ########.fr        #
#									       #
# **************************************************************************** #

# Comamad Miscs

NAME	= fractol
C_COMP	= cc
C_FLAG	= -Wall -Werror -Wextra
C_REMO	= rm -rf
C_LIBX	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# Sources & Objects

D_HDRS	= -I ./includes/
D_SRCS	= srcs/
D_OBJS	= objs/

N_SRCS	= main.c		\
	  core_init.c		\
	  core_render.c		\
	  ft_events.c		\
	  ft_math_utils.c	\
	  ft_string_utils.c	\

B_SRCS	= main_bonus.c			\
	  core_init_bonus.c		\
	  core_render_bonus.c		\
	  ft_events_bonus.c		\
	  ft_math_utils_bonus.c		\
	  ft_string_utils_bonus.c	\

F_SRCS	= $(addprefix $(D_SRCS), $(N_SRCS))

N_OBJS	= $(N_SRCS:.c=.o)
N_BOBJ	= $(B_SRCS:.c=.o)
F_OBJS	= $(addprefix $(D_OBJS), $(N_OBJS))
B_OBJS	= $(addprefix $(D_OBJS), $(N_BOBJ))

# Mandatory Rules

all		: $(NAME) 

$(D_OBJS)%.o	: $(D_SRCS)%.c
	$(C_COMP) $(C_FLAG) ${D_HDRS} -c $< ${C_LIBX} -o $@

$(D_OBJS)	:
	mkdir $(D_OBJS)

bonus		: $(D_OBJS) $(B_OBJS)
	$(C_COMP) $(C_FLAG) $(B_OBJS) ${C_LIBX} -o $(NAME)

$(NAME)		: $(D_OBJS) $(F_OBJS)
	$(C_COMP) $(C_FLAG) $(F_OBJS) ${C_LIBX} -o $(NAME)

clean		:
	${C_REMO} $(D_OBJS)

fclean		: clean
	${C_REMO} $(NAME)

re		: fclean all

# Personal Rule

setlib		:
				@cp ~/Downloads/minilibx-linux.tgz ./
				@tar zxvf minilibx-linux.tgz
				@${C_REMO} minilibx-linux.tgz
				@make --no-print-directory -C ./minilibx-linux/
				@echo "Done!"

rmvlib		:
				@${C_REMO} ./minilibx-linux
				@echo "Done!"
				

# Test Rules

test_0		:
				@echo "Wiki with Mandelbrot..: https://pt.wikipedia.org/wiki/Conjunto_de_Mandelbrot"
				./${NAME} mandelbrot

test_1		:
				@echo "Wiki with Julia Sets..: https://pt.wikipedia.org/wiki/Conjunto_de_Julia"
				./${NAME} julia 0.45 0.1428

test_2		:
				@echo "Wiki with Julia Sets..: https://pt.wikipedia.org/wiki/Conjunto_de_Julia"
				./${NAME} julia 0.285 0

test_3		:
				@echo "Wiki with Julia Sets..: https://pt.wikipedia.org/wiki/Conjunto_de_Julia"
				./${NAME} julia -0.70176 -0.3842

test_4		:
				@echo "Wiki with Julia Sets..: https://pt.wikipedia.org/wiki/Conjunto_de_Julia"
				./${NAME} julia 0.38 -0.58

test_b		:
				@echo "Kudos!"
				./${NAME} psyclover
# Phony

.PHONY: all clean fclean re bonus setlib rmvlib test_0 test_1 test_2 test_3 test_4 test_b
