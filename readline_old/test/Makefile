##
## Makefile for  in /home/bailly_j/rendu/360SH-NoScop3/editor/test/
##
## Made by Jamy Bailly
## Login   <bailly_j@epitech.net>
##
## Started on  Wed May 25 16:58:17 2016 Jamy Bailly
## Last update Wed May 25 16:58:17 2016 Jamy Bailly
##

SOURCES	= \
	main.c

OBJECTS	= $(SOURCES:.c=.o)

NAME = test

CC = gcc

RM	= rm -rf

ECHO		= /bin/echo -e

RED		= "\033[0;91m"
GREEN		= "\033[0;92m"
END		= "\033[0m"

echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)

all: build_sh $(NAME)

build_sh:
	$(MAKE) -C ../../ all DEBUG_OPT="DEBUG=true"

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -L../../ -L../../egc/ -lsh -legc -lncurses

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

clean:
	$(MAKE) -C ../../ clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C ../../ fclean
	$(RM) $(NAME)


re: fclean all

.PHONY:	all clean fclean re build_sh
