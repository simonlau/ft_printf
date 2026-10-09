NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar
ARFLAGS		= rcs
RM		= rm -f

SRCS		= ft_printf.c \
		  ft_print_char.c \
		  ft_print_nbr.c \
		  ft_print_hex.c

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= ft_printf_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): ft_printf_bonus.h

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
