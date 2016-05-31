##
## Makefile for 42sh in /home/antoine/42sh
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Fri May 27 00:21:23 2016 Valentin Pichard
## Last update Fri May 27 17:41:12 2016 Antoine Baudrand
##

include test.mk

AR 	= ar rc

UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	AR = libtool -static -o
endif

SOURCES	= \
	./bltin/cd.c \
	./bltin/cd_errors.c \
	./bltin/setenv.c \
	./bltin/unsetenv.c \
	./bltin/echo.c \
	./bltin/exit.c \
	colorize/colorize.c \
	colorize/get_color.c \
	colorize/uncolorize.c \
	readline/readline_char.c \
	readline/readline_get.c \
	readline/readline_new.c \
	readline/readline_read.c \
	readline/readline_set.c \
	readline/readline_term.c \
	readline/readline_update.c \
	readline/readline_event.c \
	lexer/error.c \
	lexer/lexer.c \
	lexer/position.c \
	lexer/source_file.c \
	lexer/token.c \
	parse_int/parse_int.c \
	parse_int/parse_and_read_int.c \
	parse_int/parse_and_read_int_base.c \
	sh.c \
	string/string.c \
	string/string_concat.c \
	string/string_copy.c \
	string/string_equals.c \
	string/string_find_char.c \
	string/string_find.c \
	string/string_starts_with.c \
	string/string_type.c \
	string/string_type_converter.c \
	env.c \
	env_tools.c

OBJECTS	= $(SOURCES:.c=.o)

DELIVERY	= false

CC		= cc

RM		= rm -rf

CFLAGS		= -W -Wall -Wextra -std=c89

LDFLAGS		= -L./egc/ -legc -lncurses

ifeq ($(DELIVERY),true)
	CFLAGS	+= -D NDEBUG
else
	CFLAGS	+= -g
endif

LIBSH		= libsh.a

LIBEGC		= egc/libegc.a

ECHO		= /bin/echo -e

RED		= "\033[0;91m"
GREEN		= "\033[0;92m"
END		= "\033[0m"

echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)

all: test/test

test/test: $(LIBEGC) $(TEST_OBJECTS) $(LIBSH)
	@$(CC) -o $@ $(TEST_OBJECTS) $(LDFLAGS) -L. -lsh -legc && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

rtest: test/test
	./test/test

vgtest: test/test
	valgrind \
		--suppressions=egc/valgrind.supp \
		--track-origins=yes \
		--num-callers=100 \
		./test/test

$(LIBSH): $(OBJECTS)
	@$(AR) $@ $^ && \
		$(ECHO) AR $@ || \
		$(call echo_error,$<)
	@ranlib $@ && \
		$(ECHO) RANLIB $@ || \
		$(call echo_error,$<)

$(LIBEGC):
	$(MAKE) -C egc/ DEBUG=true

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

delivery:
	$(MAKE) -C egc/ delivery
	$(RM) lexer/gen_lexer_h.py

glist_clean:
	$(MAKE) -C egc/ glist_clean

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJECTS)
	$(RM) $(LIBSH)
	$(MAKE) -C egc/ clean

fclean: clean
	$(RM) test/test
	$(MAKE) -C egc/ fclean

re: fclean all

.PHONY: all clean fclean re glist_clean rtest vgtest
