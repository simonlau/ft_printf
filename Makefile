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

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

TEST_DIR	= tests
TEST_BINS	= $(TEST_DIR)/ft_printf_test $(TEST_DIR)/ft_printf_bonus_test

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(LIBFT) $(OBJS) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): ft_printf_bonus.h

TEST_CFLAGS	= $(CFLAGS) -Wno-format-security

test: bonus
	$(CC) $(TEST_CFLAGS) -I. $(TEST_DIR)/ft_printf_test.c $(NAME) \
		-o $(TEST_DIR)/ft_printf_test
	$(CC) $(TEST_CFLAGS) -I. $(TEST_DIR)/ft_printf_bonus_test.c $(NAME) \
		-o $(TEST_DIR)/ft_printf_bonus_test
	./$(TEST_DIR)/ft_printf_test --report-error
	./$(TEST_DIR)/ft_printf_bonus_test --report-error

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_BINS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus test
