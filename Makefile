##
## Makefile for minishell1 in /home/isos/Workspace/Epitech/PSU_2016_minishell1
## 
## Made by Sébastien Jacobin
## Login   <sebastien.jacobin@epitech.net>
## 
## Started on  Sun Dec  4 02:29:28 2016 Sébastien Jacobin
## Last update Sat Dec 10 14:40:34 2016 Sébastien Jacobin
##

CC	= gcc

SRC	=	get_next_line.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_shell.c	\
		my_strcmp.c	\
		my_strlen.c	\
		my_str_to_wordtab.c	\
		path.c	\
		signal.c	\
		access.c	\
		pipe.c	\
		my_ptrlen.c	\
		my_fork.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I include/

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~

re:	fclean all
