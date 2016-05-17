## load_2d_arr_from_file.c		\
##
## Makefile for my_MakeFile in /home/bauer_b/rendu/Piscine_C_infinadd/lib/my
## 
## Made by Aurélien BAUER
## Login   <bauer_b@epitech.net>
## 
## Started on  Mon Oct 19 10:25:08 2015 Aurélien BAUER
## Last update Sun Feb 28 16:30:18 2016 
##

CC	= gcc

RM	= rm -f *~

NAME	= libtekgui.a

LIB	= -L. -ltekgui -L/home/${USER}/.froot/lib/	\
				-llapin			\
				-L/usr/local/lib	\
				-lsfml-audio		\
				-lsfml-graphics		\
				-lsfml-window		\
				-lsfml-system		\
				-lstdc++		\
				-ldl			\
				-lm -I.			\
				-rdynamic

FLAGS	=  -W -Wall -Werror


SRCS	= srcs/blit_tektext.c		\
	  srcs/change_checkbox.c	\
	  srcs/change_textbox.c		\
	  srcs/display_button.c		\
	  srcs/display_checkbox.c	\
	  srcs/display_elem.c		\
	  srcs/display_textbox.c	\
	  srcs/init_plan.c		\
	  srcs/keyboard.c		\
	  srcs/mouse_pos.c		\
	  srcs/my_backnlen.c		\
	  srcs/my_char_str_cat.c	\
	  srcs/my_returnlen.c		\
	  srcs/my_suppr_char_in_str.c	\
	  srcs/print_key.c		\
	  srcs/square.c			\
	  srcs/circle.c			\
	  srcs/tekgui_display.c		\
	  srcs/tekgui_load.c		\
	  srcs/teklettre.c		\
	  srcs/tekpixel.c		\
	  srcs/text.c			\
	  srcs/get_next_line.c		\
	  srcs/addnew_elem_inlist.c	\
	  srcs/my_str_to_wordtab.c	\
	  srcs/str_to_wordchar.c	\
	  srcs/my_strlen.c		\
	  srcs/my_getnbr.c		\
	  srcs/fs_open_file.c		\
	  srcs/change_button.c		\
	  srcs/tekfunction.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)	\
	&& ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
