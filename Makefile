##
## Makefile for  in /Users/pichar_v/Documents/tek1/360SH-NoScop3/
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Sat Apr 16 11:50:36 2016 Valentin Pichard
## Last update Sat Apr 16 14:31:20 2016 Valentin Pichard
##

include libcw.mk
include test.mk

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

LIBCW_NAME	= libcw.a
LIBCW		= libcw/$(LIBCW_NAME)

LIBEGC		= egc/libegc.a

ECHO		= /bin/echo -e

RED		= "\033[0;91m"
GREEN		= "\033[0;92m"
END		= "\033[0m"

echo_error	= $(ECHO) $(RED) $(1) "[ERROR]" $(END)

all: test/test

test/test: $(LIBEGC) $(TEST_OBJECTS) $(LIBCW)
	$(CC) -o $@ $^ $(LDFLAGS)

rtest: test/test
	./test/test

vgtest: test/test
	valgrind --suppressions=egc/valgrind.supp ./test/test

$(LIBCW): $(LIBCW_OBJECTS)
	ar rc $@ $^
	ranlib $@

$(LIBEGC):
	$(MAKE) -C egc/ DEBUG=true

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		$(ECHO) CC $< || \
		$(call echo_error,$<)

glist_clean:
	$(MAKE) -C egc/ glist_clean

clean:
	$(RM) $(LIBCW_OBJECTS)
	$(RM) $(TEST_OBJECTS)
	$(RM) $(LIBCW)
	$(MAKE) -C egc/ clean

fclean: clean
	$(RM) test/test
	$(MAKE) -C egc/ fclean

re: fclean all

.PHONY: all clean fclean re glist_clean rtest vgtest
