##
## Makefile for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
## 
## Made by Sébastien Jacobin
## Login   <sebastien.jacobin@epitech.net>
## 
## Started on  Sun Dec  4 02:29:28 2016 Sébastien Jacobin
## Last update Thu Dec 29 22:53:01 2016 Sébastien Jacobin
##

CC	= gcc

SRC	=	src/get_next_line.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_strcmp.c	\
		src/my_strlen.c	\
		src/my_str_to_wordtab.c	\
		src/signal.c	\
		src/pipe.c	\
		src/my_ptrlen.c	\
		src/my_fork.c	\
		src/builtin.c	\
		src/my_shell.c	\
		src/path.c	\
		src/access.c	\
		src/env.c	\
		src/check.c	\
		src/my_getnbr.c


OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I include/ -Werror

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~

re:	fclean all
