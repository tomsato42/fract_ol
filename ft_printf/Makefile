CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
NAME = libftprintf.a
SRC_DIR = ./src
LIBFT_DIR = ./libft
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDE = -I ./include -I $(LIBFT_DIR)
RM = rm -f
TEST = test_exec
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
.PHONY : all clean fclean re test
all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
test: $(NAME) testmain.c
	$(CC) $(CFLAGS) testmain.c -o $(TEST) -L. -lftprintf
	./$(TEST)
