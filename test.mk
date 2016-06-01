##
## test.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:39:22 2016 antoine
## Last update Sat Apr 16 13:47:52 2016 Valentin Pichard
##

TEST_SOURCES_NAMES	= test.c \
			test_colorize.c \
			test_lexer.c \
			test_parse_int.c \
			test_string_concat.c \
			test_string_find.c \
			test_string_find_char.c \
			test_string_type.c \
			test_exec.c \
			test_string_type_convert.c \
			test_suites.c

TEST_SOURCES		= $(foreach file,$(TEST_SOURCES_NAMES), \
			test/unit/$(file))

TEST_OBJECTS		= $(TEST_SOURCES:.c=.o)
