NAME	=	libftprintf.a

SRCS	= \
		ft_printf.c\
		percentualizeitor.c\
		ft_putnbr_pf.c\
		ft_strchr.c\
		print_string.c

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

