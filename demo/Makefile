## load_2d_arr_from_file.c		\
##
## Makefile for my_MakeFile in /home/bauer_b/rendu/Piscine_C_infinadd/lib/my
## 
## Made by Aurélien BAUER
## Login   <bauer_b@epitech.net>
## 
## Started on  Mon Oct 19 10:25:08 2015 Aurélien BAUER
## Last update Sun Feb 28 15:42:32 2016 
##

CC	= gcc

RM	= rm -f *~

NAME	= tekgui

LIB	= -L../ -ltekgui -L/home/${USER}/.froot/lib/	\
				-llapin			\
				-L/usr/local/lib	\
				-lsfml-audio		\
				-lsfml-graphics		\
				-lsfml-window		\
				-lsfml-system		\
				-lstdc++		\
				-ldl			\
				-lm -I. 		\
				-rdynamic

FLAGS	=


SRCS	= main.c


OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
