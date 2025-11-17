CC = cc
FLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

C_FILES = ft_printf.c ft_get_arg_info.c ft_print_types.c \
ft_print_c_type.c ft_print_p_type.c ft_print_s_type.c \
ft_print_di_type.c ft_print_u_type.c ft_print_x_type.c \
ft_len_num_base.c ft_putnbr_base_fd.c

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
	@$(CC) $(NAME) 
	@./a.out

testwww: 
	@$(CC) $(FLAGS) $(NAME) 
	@./a.out

#norm:
#	@norminette

.PHONY: all clean fclean re bonus