NAME	=	libftprintf.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

AR		=	ar rc

RM		=	rm -f

INCDIR	=	./includes/

SRCDIR	=	./srcs/

SRCNAME	=	check_digit.c \
			free_flag.c \
			ft_bzero.c \
			ft_printf.c \
			ft_putadnbr.c \
			ft_putchar.c \
			ft_putlxnbr.c \
			ft_putusnbr.c \
			ft_putxnbr.c \
			ft_strlen.c \
			ft_putnbr.c \
			init_flag.c \
			pack_flag.c \
			pack_option.c \
			pack_option_asta.c \
			print_address.c \
			print_c.c \
			print_lx.c \
			print_num.c \
			print_percent.c \
			print_rest.c \
			print_str.c \
			print_u.c \
			print_x.c \
			switch_act.c

SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS}	-I ${INCDIR} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR}	${NAME}	${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
