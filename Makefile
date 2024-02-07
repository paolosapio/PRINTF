NAME	=	libftprintf.a

SRCS	= \
		ft_int_to_exa.c\
		ft_printf.c\
		ft_putchar_pf.c\
		ft_putnbr_pf.c\
		ft_strchr.c\
		percentualizeitor.c\
		print_string.c\
		ft_if_pointer.c\
		ft_u.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc 

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

.PHONY	:	all clean fclean re

re	:	fclean all

