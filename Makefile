##
## Makefile for 360SH-NoScop3 in /home/antoine/360SH-NoScop3
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Fri May 27 00:21:23 2016 Valentin Pichard
## Last update Fri Jun  3 19:28:17 2016 Pierre-Emmanuel Jacquier
##

include test.mk

AR 	= ar rc

NAME	= 42sh

UNAME_S	:= $(sh uname -s)
ifeq ($(UNAME_S),Darwin)
	AR = libtool -static -o
endif

SOURCES	= \
	bltins/cd.c \
	bltins/cd_errors.c \
	bltins/echo.c \
	bltins/env_cmd.c \
	bltins/exit.c \
	bltins/setenv.c \
	bltins/unsetenv.c \
	colorize/colorize.c \
	colorize/colorize_extend.c \
	colorize/get_color.c \
	colorize/uncolorize.c \
	ctrl_d.c \
	env.c \
	env_tools.c \
	exec.c \
	expand_variables.c \
	file/exist.c \
	file/file.c \
	file/insert.c \
	file/read.c \
	lexer/error.c \
	lexer/get_position.c \
	lexer/lex_symbols.c \
	lexer/lexer.c \
	lexer/lexer_extend.c \
	lexer/position.c \
	lexer/source_file.c \
	lexer/syntax_error.c \
	lexer/token.c \
	lexer/token_list.c \
	lexer/token_type.c \
	parse_int/parse_int.c \
	parse_int/parse_and_read_int.c \
	parse_int/parse_and_read_int_base.c \
	readline/readline_ascii_event.c\
	readline/readline_char.c \
	readline/readline_event_ctrl.c\
	readline/readline_event.c \
	readline/readline_get.c \
	readline/readline_new.c \
	readline/readline_print.c \
	readline/readline_read.c \
	readline/readline_set.c \
	readline/readline_term.c \
	readline/readline_update.c \
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
	toolbox/display.c \
	toolbox/prompt.c \
	parser/parser.c \
	parser/node.c \

OBJECTS	= $(SOURCES:.c=.o)

DELIVERY	= false

CC		= cc

RM		= rm -rf

CFLAGS		= -W -Wall -Wextra

LDFLAGS		= -L./egc -legc -lncurses

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

EGC_DEBUG	= $(or 	$(findstring vgtest,$(MAKECMDGOALS)), \
			$(findstring vg,$(MAKECMDGOALS)))

ifeq ($(EGC_DEBUG),)
	DEBUG_OPT	=
else
	DEBUG_OPT	= DEBUG=true
endif


echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)

all: $(NAME)

$(NAME): $(LIBEGC) $(LIBSH) main.o
	@$(CC) -o $@ main.o -L. -lsh $(LDFLAGS) && \
		$(ECHO) CC $@ || \
		$(call echo_error,$@)

test/test: $(LIBEGC) $(LIBSH) $(TEST_OBJECTS)
	@$(CC) -o $@ $(TEST_OBJECTS) -L. -lsh $(LDFLAGS) && \
		$(ECHO) CC $@ || \
		$(call echo_error,$@)

rtest: test/test
	./test/test

vgtest: test/test
	valgrind \
		--suppressions=egc/valgrind.supp \
		--track-origins=yes \
		--num-callers=100 \
		./test/test

vg: $(NAME)
	valgrind \
		--suppressions=egc/valgrind.supp \
		--track-origins=yes \
		--num-callers=100 \
		./$(NAME)

$(LIBSH): $(OBJECTS)
	@$(AR) $@ $^ && \
		$(ECHO) AR $@ || \
		$(call echo_error,$<)
	@ranlib $@ && \
		$(ECHO) RANLIB $@ || \
		$(call echo_error,$<)

$(LIBEGC):
	$(MAKE) -C egc/ $(DEBUG_OPT)

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

delivery:
	$(MAKE) -C egc/ delivery
	$(RM) test/unit/log_parsing.rules
	$(RM) README.md

glist_clean:
	$(MAKE) -C egc/ glist_clean

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJECTS)
	$(RM) main.o
	$(RM) $(LIBSH)
	$(MAKE) -C egc/ clean

fclean: clean
	$(RM) test/test
	$(MAKE) -C egc/ fclean
	$(RM) $(NAME)
	$(RM) onch

re: fclean all

.PHONY: all clean fclean re glist_clean rtest vgtest
