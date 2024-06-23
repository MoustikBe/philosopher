NAME		= philosopher
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -c
RM			= rm -rf

SOURCES		= src/main src/ft_usleep src/micro_libft src/monitoring \
			  src/parsing src/routine src/store_data src/sub_process \
			  src/thread_mngr
		 	  

OBJECTS     = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)
	@echo "\033[33;32mCompilation finish with no problem ✅"

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
	@echo "\033[33;36mAll the file his delete correctly ✅"

all : $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
