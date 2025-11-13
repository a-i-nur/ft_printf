CC = cc
FLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

C_FILES = ft_printf.c

NAME = libftprintf.a
INCLUDES = includes
SOURCES = sources
OBJECTS = object_files
LIBFT = libft

O_FILES = $(addprefix $(OBJECTS)/,$(C_FILES:.c=.o))

all: $(NAME)

bonus: all

$(NAME): $(O_FILES)
	@make -C $(LIBFT)/
	@cp $(LIBFT)/libft.a $(NAME)
	@ar rcs $(NAME) $(O_FILES)
	@echo "$(NAME) is ready"

$(OBJECTS):
	@mkdir -p $(OBJECTS)

$(OBJECTS)/%.o: $(SOURCES)/%.c $(INCLUDES)/ft_printf.h | $(OBJECTS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -rf $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME) a.out
	@make fclean -C $(LIBFT)
	@echo "All files were deleted"

re: fclean all

test: 
	@$(CC) $(FLAGS) $(NAME) 
	@./a.out

#norm:
#	@norminette

.PHONY: all clean fclean re bonus