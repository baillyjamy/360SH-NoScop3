##
## Makefile for  in /Users/pichar_v/Documents/tek1/360SH-NoScop3/
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Sat Apr 16 11:50:36 2016 Valentin Pichard
## Last update Sat Apr 16 12:02:45 2016 Valentin Pichard
##

include libcw.mk
include test.mk

DELIVERY	= true

CC		= cc

RM		= rm -rf

CFLAGS		= -W -Wall -Wextra -std=c89

ifeq ($(DELIVERY),true)
	CFLAGS	+= -D NDEBUG
else
	CFLAGS	+= -g
endif

LIBCW_NAME	= libcw.a
LIBCW		= libcw/$(LIBCW_NAME)

ECHO		= /bin/echo -e

RED		= "\033[0;91m"
GREEN		= "\033[0;92m"
END		= "\033[0m"

echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)

all: test/test

test/test: $(TEST_OBJECTS) $(LIBASM) $(LIBCW)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBCW): $(LIBCW_OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

clean:
	$(RM) $(LIBCW_OBJECTS)
	$(RM) $(TEST_OBJECTS)
	$(RM) $(LIBCW)

fclean: clean
	$(RM) test/test

re: fclean all

.PHONY: all clean fclean re
