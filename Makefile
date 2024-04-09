CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./mandatory/srcs/parsing_utilities.c \
./mandatory/srcs/push.c \
./mandatory/srcs/reverse_rotate.c \
./mandatory/srcs/swap.c \
./mandatory/srcs/sorting_utilities.c \
./mandatory/srcs/algo.c \
./mandatory/srcs/tiny_sort.c \
./mandatory/srcs/rotate.c	\
./mandatory/srcs/utils.c \
./mandatory/srcs/free.c \
./mandatory/srcs/target.c \
./mandatory/srcs/cost.c \
./mandatory/srcs/sort.c \
./mandatory/srcs/sort2.c \
./mandatory/srcs/chunk.c
BONUS_SRCS = ./bonus/srcs/push_bonus.c \
./bonus/srcs/free_bonus.c \
./bonus/srcs/utils_bonus.c \
./bonus/srcs/rotate_bonus.c \
./bonus/srcs/get_next_line_bonus.c \
./bonus/srcs/get_next_line_utils_bonus.c \
./bonus/srcs/parsing_utilities_bonus.c \
./bonus/srcs/reverse_rotate_bonus.c \
./bonus/srcs/swap_bonus.c \
./bonus/srcs/bonus_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(BONUS_SRCS:.c=.o)
LIBFT_MAKEFILE = ./libft/Makefile
INCLUDE = ./mandatory/push_swap.h
BONUS_INCLUDE = ./bonus/checker_bonus.h
LIBFT_AR = ./libft/libft.a
LIBFT_INCLUDE = ./libft/libft.h
ENTRY = ./mandatory/srcs/push_swap.c
BONUS_ENTRY = ./bonus/srcs/checker_bonus.c
BONUS_EXEC = checker
NAME = push_swap
FSANITIZE= -g -fsanitize=address

all: $(NAME)

bonus: $(BONUS_EXEC)

$(LIBFT_AR): $(LIBFT_INCLUDE)
	@make -C libft

$(NAME): $(LIBFT_INCLUDE) $(INCLUDE) $(OBJS) $(LIBFT_AR)
	@$(CC) $(FLAGS) $(FSANITIZE) $(ENTRY) $(OBJS) -o $(NAME)  $(LIBFT_AR)

$(BONUS_EXEC): $(LIBFT_INCLUDE) $(BONUS_INCLUDE) $(OBJSB) $(LIBFT_AR)
	@$(CC) $(FLAGS) $(FSANITIZE)  $(BONUS_ENTRY) $(OBJSB) -o $(BONUS_EXEC) $(LIBFT_AR)

clean:
	@make clean -C libft
	@rm -rf $(OBJS) $(OBJSB)
fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME) $(BONUS_EXEC)
re: fclean all

.PHONY: libft