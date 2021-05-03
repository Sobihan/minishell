CC		=	gcc

RM		=	rm -f

NAME		=	mysh

SRCS		=	srcs/main.c	\
				srcs/mystrlen.c	\
				srcs/mystrcmp.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS = -Iinclude

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re