##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- Lib compilation
##

SRC		=	my_atoi.c \
			my_getnbr.c \
			my_itoa.c \
			my_putchar.c \
			my_putfloat.c \
			my_put_nbr.c \
			my_putnbr_base.c \
			my_putstr.c \
			my_revstr.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_str_isalpha.c \
			my_str_islower.c \
			my_str_isnum.c \
			my_strlen.c \
			my_strncat.c \
			my_strncmp.c \
			my_strncpy.c \
			my_strstr.c \
			my_isneg.c \
			my_sort_int_array.c \
			my_swap.c \
			my_strncpy_after.c \
			is_stris_in.c \
			is_nstris_in.c \
			my_realloc.c \
			my_calloc.c \
			my_str_to_word_array.c \
			my_strcpy_tab.c \
			my_str_isalphanum.c \
			get_next_line.c \
			is_chr_in_str.c \
			big_strcat.c \

NAME		= 	libmy.a

OBJ		=	$(SRC:.c=.o)

RM 		=	@rm -f

CFLAGS	= 	-Wall -Wextra -W

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) *.~

fclean: clean
	$(RM) $(NAME)

re: fclean all
