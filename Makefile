# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 15:20:10 by simon.lau         #+#    #+#              #
#    Updated: 2026/10/18 17:15:09 by simon.lau        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
AR := ar
ARFLAGS := rcs

TST_URL := https://github.com/rdentato/tst.git
TST_DIR := tst

CFLAGS := -Wall -Wextra -Werror -I$(TST_DIR)/src -I.
SANFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -fno-sanitize-recover=all
ifeq ($(shell uname -s),Linux)
    LDFLAGS += -Wl,--as-needed -lbsd
endif

TEST_DIR := tests
TEST_SRCS := $(wildcard $(TEST_DIR)/ft_*_test.c)
TEST_BINS := $(TEST_SRCS:.c=)
SRCS := ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
NAME := libft.a

.PHONY: all clean fclean re test run-tests coverage clone-tst wipe build-tests clean-tests

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

TEST_CFLAGS = $(CFLAGS) -I. -I$(TEST_DIR)

build-tests: $(TEST_BINS)

$(TEST_DIR)/%: $(TEST_DIR)/%.c $(TEST_DIR)/test.h $(TEST_DIR)/test_utils.c libft.h $(NAME) | clone-tst
	$(CC) $(TEST_CFLAGS) $< tests/test_utils.c $(NAME) $(LDFLAGS) -o $@

test: clean-tests
	$(MAKE) build-tests TEST_CFLAGS="$(CFLAGS) $(SANFLAGS) -I. -I$(TEST_DIR)"
	@for t in $(TEST_BINS); do ASAN_OPTIONS=allocator_may_return_null=1 ./$$t --report-error || exit 1; done

clean-tests:
	rm -f $(TEST_BINS)

clone-tst:
	@if [ ! -d $(TST_DIR) ]; then git clone --depth 1 $(TST_URL) $(TST_DIR); fi

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean: clean-tests
	rm -f $(OBJS) $(DEPS) $(TEST_BINS)
	rm -f *.gcda *.gcno tests/*.gcda tests/*.gcno
	rm -rf $(TEST_BINS:=.dSYM) all-tests all-tests.dSYM coverage .coverage

fclean: clean
	rm -f $(NAME)

re: fclean all
