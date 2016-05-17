/*
** change_button.c for  in /home/tek/rendu/gfx_tekgui/srcs
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 11:11:37 2016 
** Last update Sat Feb 27 12:21:38 2016 
*/

#include "tekgui.h"

void		test()
{
  write(1, "OK\n", 3);
}

void		change_button(const t_bunny_position *mouse_pos,
			      t_list *list, t_elem *elem)
{
  void		(*ptr)();
  if ((mouse_pos->x >= elem->pos.x &&
       mouse_pos->x <= (elem->pos.x + elem->width))
      && (mouse_pos->y >= elem->pos.y &&
          mouse_pos->y <= (elem->pos.y + elem->height)))
    {
      elem->is_check = 1;
      ptr = tekfunction(elem->name_fonction);
      ptr();
    }
  list->data = (void*)elem;
}
