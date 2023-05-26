# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/05/26 16:32:17 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Constants

NAME		= push_swap
BONUSNAME	= checker

CFLAGS 		= -Wall -Wextra -Werror
CPPFLAGS	= -I/usr/include -I./inc					# search in directories for included Makefiles
LDFLAGS		= -L./libft -L/usr/lib						# search for libraries in libft and /usr/lib
LDLIBS		= -lft 										# link libraries: libft
OPTION 		= -c 										# -c generates object files, -O3 adds compile time, but reduces execution time and code size 					
DEBUG		= -g
CC 			= cc

INCDIR		= ./inc/
INCLIST		= error.h initiate.h input_check.h median.h ops.h push_swap.h \
			quicksort.h simple_sort.h sort.h terminate.h utils_insert.h \
			utils_ops.h utils_quicksort.h utils.h
INCLIST_B	= checker.h error.h initiate.h input_check.h ops.h push_swap.h \
			terminate.h utils_ops.h utils.h
INC			= $(addprefix ${INCDIR}, ${INCLIST})
INC_B		= $(addprefix ${INCDIR}, ${INCLIST_B})

SRCDIR		= ./src/
SRCLIST		= initiate.c input_check.c main.c median.c ops_a.c ops_b.c quicksort.c \
			simple_sort.c sort.c terminate.c utils_insert.c utils_ops.c utils_quicksort.c \
			utils.c
SRCLIST_B	= checker.c initiate.c input_check.c ops_a.c ops_b.c terminate.c \
			utils_ops.c utils.c
SRC			= $(addprefix ${SRCDIR}, ${SRCLIST})
SRC_B		= $(addprefix ${SRCDIR}, ${SRCLIST_B})


OBJDIR		= ./obj/
OBJLIST		= $(SRCLIST:%.c=%.o)
OBJLIST_B	= $(SRCLIST_B:%.c=%.o)
OBJ			= $(addprefix ${OBJDIR}, ${OBJLIST})
OBJ_B		= $(addprefix ${OBJDIR}, ${OBJLIST_B})


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

bonus:			$(BONUSNAME)

$(NAME):		$(OBJDIR) $(OBJ)
				@echo "\n$(MAGENTA)Compiling: $@ $(DEF_COLOUR)\n"
				@$(MAKE) all --no-print-directory -C ./libft
				@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(DEBUG) -o $@
				@echo "\n$(FAT_MAGENTA)$@ compiled! 🍾$(DEF_COLOUR)"

$(BONUSNAME):	$(OBJDIR) $(OBJ_B)
				@echo "\n$(MAGENTA)Compiling: $@ $(DEF_COLOUR)\n"
				@$(MAKE) all --no-print-directory -C ./libft
				@$(CC) $(OBJ_B) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(DEBUG) -o $@
				@echo "\n$(FAT_MAGENTA)$@ compiled! 🔥$(DEF_COLOUR)"

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
				@rm -f $(BONUSNAME)
				@echo "$(FAT_RED)executable cleaned! 👹$(DEF_COLOUR)"

re: 			fclean all

valgr:			
				@valgrind --leak-check=full\
						--show-leak-kinds=all\
						--trace-children=no\
						--track-fds=no\
						--log-file=valgrind-out.txt\
						./push_swap 56 5 80 55 22 47 63 1 14 42 57 20 4
				@less ./valgrind-out.txt

.PHONY: 		all bonus clean fclean re valgr
