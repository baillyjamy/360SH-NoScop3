##
## Makefile for  in /Users/pichar_v/Documents/tek1/360SH-NoScop3/
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Sat Apr 16 11:50:36 2016 Valentin Pichard
## Last update Fri Apr 22 18:30:15 2016 Valentin Pichard
##

include test.mk

SOURCES	= \
	colorize/colorize.c \
	colorize/get_color.c \
	colorize/uncolorize.c \
	lexer/lexer.c \
	lexer/position.c \
	lexer/source_file.c \
	parse_int/parse_int.c \
	parse_int/parse_and_read_int.c \
	parse_int/parse_and_read_int_base.c \
	shell.c \
	string/string.c \
	string/string_concat.c \
	string/string_copy.c \
	string/string_equals.c \
	string/string_find_char.c \
	string/string_find.c \
	string/string_starts_with.c \
	string/string_type.c \
	string/string_type_converter.c

OBJECTS	= $(SOURCES:.c=.o)

DELIVERY	= false

CC		= cc

RM		= rm -rf

CFLAGS		= -W -Wall -Wextra -std=c89

LDFLAGS		= -L./egc/ -legc

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
	@$(CC) -o $@ $^ $(LDFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

rtest: test/test
	./test/test

vgtest: test/test
	valgrind --suppressions=egc/valgrind.supp ./test/test

$(LIBSH): $(OBJECTS)
	@ar rc $@ $^ && \
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
