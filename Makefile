NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS += -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all
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
TEST_SRCS	= $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS	= $(TEST_SRCS:.c=)

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

TEST_CFLAGS	= $(CFLAGS) -I. -I$(TEST_DIR)

$(TEST_DIR)/%: $(TEST_DIR)/%.c $(NAME)
	$(CC) $(TEST_CFLAGS) $< $(NAME) -o $@

build-tests: $(TEST_BINS)

test: build-tests
	for t in $(TEST_BINS); do ./$$t --report-error || exit 1; done

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_BINS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus test build-tests
