CC = cc
FLAGS = -Wall -Wextra -Werror -I.

C_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

C_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

O_FILES = $(C_FILES:.c=.o)

O_BONUS= $(C_BONUS:.c=.o)

NAME = libft.a
HEADER = libft.h

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $(NAME) $^
	@echo "Libc functions, additional functions are ready"

bonus:  $(O_FILES) $(O_BONUS)
	@ar rcs $(NAME) $^
	@echo "Bonus functions are ready"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -f $(O_FILES) $(O_BONUS)
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "All files were deleted"

re: fclean all

#test: 
#	@$(CC) $(FLAGS) $(NAME) 
#	@./a.out

#norm:
#	@norminette

.PHONY: all clean fclean re test