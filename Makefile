NAME = libftprintf.a
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			$(AR) rcs $(NAME) $(OBJS)
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)

re: fclean all