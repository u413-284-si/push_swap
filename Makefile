# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/03/31 19:29:53 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Constants

NAME		= push_swap

CFLAGS 		= -Wall -Wextra -Werror
CPPFLAGS	= -I/usr/include -I./inc					# search in directories for included Makefiles
LDFLAGS		= -L./libft -L/usr/lib						# search for libraries in libft and /usr/lib
LDLIBS		= -lft 										# link libraries: libft
OPTION 		= -c -O3									# -c generates object files, -O3 adds compile time, but reduces execution time and code size 					
DEBUG		= -g
CC 			= cc

INCDIR		= ./inc/
INCLIST		= pipex.h children.h cleanup.h commands.h error.h initiate.h \
			utils.h
INC			= $(addprefix ${INCDIR}, ${INCLIST})

SRCDIR		= ./src/
SRCLIST		= children.c cleanup.c commands.c error.c initiate.c main.c \
			utils.c
SRC			= $(addprefix ${SRCDIR}, ${SRCLIST})


OBJDIR		= ./obj/
OBJLIST		= $(SRCLIST:%.c=%.o)
OBJ			= $(addprefix ${OBJDIR}, ${OBJLIST})


#Colours

DEF_COLOUR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
LIGHT_GRAY = \033[0;97m
DARK_GRAY = \033[1;90m
FAT_RED = \033[1;91m
FAT_GREEN = \033[1;92m
FAT_YELLOW = \033[1;93m
FAT_BLUE = \033[1;94m
FAT_MAGENTA = \033[1;95m
FAT_CYAN = \033[1;96m
WHITE = \033[1;97m

#Rules

all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJ)
				@echo "\n$(MAGENTA)Compiling: $@ $(DEF_COLOUR)\n"
				@$(MAKE) all --no-print-directory -C ./libft
				@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(DEBUG) -o $@
				@echo "\n$(FAT_MAGENTA)$@ compiled! 🍾$(DEF_COLOUR)"

$(OBJDIR)%.o:	$(SRCDIR)%.c $(INC)
				@$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTION) $(DEBUG) $< -o $@

$(OBJDIR):
				@mkdir $@

clean:
				@$(MAKE) clean --no-print-directory -C ./libft
				@rm -rf $(OBJDIR)
				@echo "$(DARK_GRAY)object files cleaned! 🦦$(DEF_COLOUR)\n"

fclean: 		clean
				@$(MAKE) fclean --no-print-directory -C ./libft
				@rm -f $(NAME)
				@echo "$(FAT_RED)executable cleaned! 👹$(DEF_COLOUR)"

re: 			fclean all

valgr:			
				@valgrind --leak-check=full\
						--show-leak-kinds=all\
						--trace-children=yes\
						--track-fds=yes\
						--log-file=valgrind-out.txt\
						./pipex infile "wc" "cat" outfile
				@less ./valgrind-out.txt

valgr_b:			
				@valgrind --leak-check=full\
						--show-leak-kinds=all\
						--trace-children=yes\
						--track-fds=yes\
						--log-file=valgrind-out.txt\
						./super_pipex infile "wc" "wc -l" "cat" outfile
				@less ./valgrind-out.txt

.PHONY: 		all bonus clean fclean re valgr valgr_b
