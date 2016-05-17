/*
** change_checkbox.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 09:01:54 2016 
** Last update Sat Feb 27 09:02:27 2016 
*/

#include "tekgui.h"

void		change_checkbox(const t_bunny_position *mouse_pos,
				t_list *list, t_elem *elem)
{
  if ((mouse_pos->x >= elem->pos.x &&
       mouse_pos->x <= (elem->pos.x + elem->width))
      && (mouse_pos->y >= elem->pos.y &&
	  mouse_pos->y <= (elem->pos.y + elem->height)))
    {
      if (elem->is_check == 1)
	elem->is_check = 0;
      else
	elem->is_check = 1;
      list->data = (void*)elem;
    }
}
