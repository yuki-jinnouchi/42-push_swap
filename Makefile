# Program name and output directory
NAME = 					push_swap
OUTPUT_DIR = 			.

# Other directories
SOURCES_DIR =			scrs
INCLUDES_DIR =			incl
LIBFT_DIR =				libft
LIBFT_INCLUDES_DIR =	$(LIBFT_DIR)/incl

# Files
HEADERS =				$(SOURCES_DIR)/pipex.h
LIBFT =					$(LIBFT_DIR)/libft.a
LIBFT_NAME =			ft.a
SOURCES =				$(wildcard $(SOURCES_DIR)/*.c)
OBJECTS =				$(SOURCES:.c=.o)

# BONUS_SOURCES = \
# 	$(wildcard $(BONUS_DIR)/*.c)
# BONUS_OBJECTS = 	$(BONUS_SOURCES:.c=.o)
# BONUS_OBJECTS += 	$(OBJECTS)

# Compiler and options
CC = 					cc
CFLAGS += 				-Wall -Wextra -Werror
DEST = 					$(OUTPUT_DIR)

# Phony targets]
.PHONY: all clean fclean re libft bonus aclean ac ar

# Targets
all: $(NAME)
$(NAME): $(LIBFT) $(OBJECTS)
	@echo "----------------"
	@echo "make OBJECTS done.\n"
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) $^ -lft -o $@
	@echo "----------------"
	@echo "make $(NAME) done.\n"
	@echo "change permission of $(NAME)"
	chmod -x $(NAME)
	@echo "----------------"
	@echo "change permission of $(NAME) done.\n"

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_INCLUDES_DIR) -I $(INCLUDES_DIR) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	make -C libft clean
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	make -C libft fclean
re: fclean all

# libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# # bonus
# bonus: all $(BONUS_OBJECTS)
# 	ar rcs $(NAME) $(BONUS_OBJECTS)

# non mandatory
aclean: all clean
ac: all clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)