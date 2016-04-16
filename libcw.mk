##
## libcw.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar  2 21:35:00 2016 antoine
## Last update Sat Apr 16 13:50:03 2016 Valentin Pichard
##

LIBCW_SOURCES_NAMES = 	char_type_generic.c \
			char_type_converter.c \
			int_to_malloced_string.c \
			int_to_string_generic.c \
			int_to_string_get_length.c \
			parse_int_generic.c \
			parse_and_read_int.c \
			parse_and_read_int_base.c \
			position_generic.c \
			print_string.c \
			print_int.c \
			print_char.c \
			position_generic.c \
			source_file.c \
			string_generic.c \
			string_concat.c \
			string_copy.c \
			string_equals.c \
			string_find_char.c \
			string_find.c \
			string_reader_generic.c \
			string_starts_with.c \
			string_type_generic.c \
			string_type_converter.c

LIBCW_SOURCES		= $(foreach file,$(LIBCW_SOURCES_NAMES), \
			libcw/$(file))

LIBCW_OBJECTS		= $(LIBCW_SOURCES:.c=.o)
