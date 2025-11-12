CC = cc
FLAGS = -Wall -Wextra -Werror -I.

C_PRINTF_FILES = ft_printf.c

NAME = libftprintf.a
INCLUDES = includes
SOURSEC = sources 
OBJECTS = object_files

O_FILES = $(addprefix $(OBJECTS)/,$(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $^
	@echo "$(NAME) is ready"

$(OBJECTS)/%.o: $(SOURCES)/%.c $(INCLUDES)/ft_printf.h
	@mkdir -p $(OBJECTS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -f $(O_FILES) 
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "All files were deleted"

re: fclean all

#test: 
#	@$(CC) $(FLAGS) $(NAME) 
#	@./a.out

#norm:
#	@norminette

.PHONY: all clean fclean re test