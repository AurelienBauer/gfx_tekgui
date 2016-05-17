/*
** change_textbox.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 09:00:49 2016 
** Last update Sat Feb 27 09:01:13 2016 
*/

#include "tekgui.h"

void		change_textbox(const t_bunny_position *mouse_pos,
			       t_list *list, t_elem *elem)
{
  if ((mouse_pos->x >= elem->pos.x &&
       mouse_pos->x <= (elem->pos.x + elem->width))
      && (mouse_pos->y >= elem->pos.y &&
	  mouse_pos->y <= (elem->pos.y + elem->height)))
    elem->is_check = 1;
  else
    elem->is_check = 0;
  list->data = (void*)elem;
}
