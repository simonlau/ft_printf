# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 15:20:10 by simon.lau         #+#    #+#              #
#    Updated: 2026/10/03 15:52:56 by simon.lau        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
AR := ar
ARFLAGS := rcs

THEFT_URL := https://github.com/silentbicycle/theft.git
THEFT_DIR := theft

CFLAGS := -Wall -Wextra -Werror -I$(THEFT_DIR)/inc -I.
CFLAGS += -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all
LDFLAGS += -Wl,--as-needed -lbsd

TESTS := $(basename $(notdir $(wildcard tests/*_test.c)))
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

.PHONY: all clean fclean re test run-tests coverage clone-theft wipe all-tests run-all

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

test: $(TESTS)

ASAN_OPTIONS := allocator_may_return_null=1
%_test: %.c tests/%_test.c tests/registry.c $(NAME) $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

all-tests: tests/all-tests.c tests/registry.c $(wildcard tests/ft_*.c) $(NAME) $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -Itests -DALL_TESTS -o $@ tests/all-tests.c tests/registry.c $(wildcard tests/ft_*.c) $(NAME) $(THEFT_DIR)/build/libtheft.a -lm

run-all: all-tests
	ASAN_OPTIONS=$(ASAN_OPTIONS) ./all-tests

$(THEFT_DIR)/build/libtheft.a:
	$(MAKE) -C $(THEFT_DIR)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clone-theft:
	git clone --depth 1 $(THEFT_URL) $(THEFT_DIR)

clean:
	rm -f $(OBJS) $(DEPS) $(TESTS)
	rm -f *.gcda *.gcno tests/*.gcda tests/*.gcno
	rm -rf $(TESTS:=.dSYM) all-tests all-tests.dSYM coverage .coverage

fclean: clean
	rm -f $(NAME)

re: fclean all

run-tests: $(TESTS)
	@for test in $(TESTS); do \
		ASAN_OPTIONS=$(ASAN_OPTIONS) ./$$test || exit 1; \
	done

coverage: run-tests
	@mkdir -p coverage
	@gcov -p -o . $(SRCS) 2>/dev/null || true
	@mv *.gcov coverage/ 2>/dev/null || true
	@echo "Coverage reports generated in coverage/"

wipe: fclean
	rm -rf docs tests raw wiki
	rm skills-lock.json
