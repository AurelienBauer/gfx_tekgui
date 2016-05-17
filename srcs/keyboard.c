/*
** keyboard.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Tue Feb 23 19:39:21 2016 
** Last update Sat Feb 27 09:18:52 2016 
*/

#include "tekgui.h"

void		keyboard(t_bunny_event_state sta,
			 t_bunny_keysym sym,
			 t_list *list)
{
  if (sta == GO_DOWN && sym == BKS_RETURN)
    print_key(list, '\n');
  else if (sta == GO_DOWN)
    print_key(list, sym + 97);
}
