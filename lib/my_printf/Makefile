##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib - compil printf
##

SRC	=	my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_strlen.c \
		my_putfloat.c \
		my_putnbr_base.c \
		my_putstr_oct.c \
		my_putnstr.c \
		my_strncpy.c \
		my_getnbr.c \
		my_put_unb_base.c \
		my_printf_option.c \
		my_printf_option2.c \
		function_printf.c \
		my_printf.c \

NAME	= 	libprintf.a

OBJ		=	$(SRC:.c=.o)

RM 		=	@rm -f

CFLAGS	= 	-Wall -Wextra -W

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all
