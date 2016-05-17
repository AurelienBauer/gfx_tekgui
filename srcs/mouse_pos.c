/*
** mouse_pos.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Fri Feb 19 14:42:04 2016 
** Last update Sat Feb 27 11:11:08 2016 
*/

#include "tekgui.h"

void		mouse(const t_bunny_position *mouse_pos, t_list *list)
{
  const bool	*key;
  static int	is_pass = 0;
  t_elem        *elem;

  key = bunny_get_mouse_button();
  if (key[BMB_LEFT] == true)
    is_pass = 1;
  if (key[BMB_LEFT] == false && is_pass == 1)
    {
      while (list != NULL)
	{
	  elem = (t_elem*)list->data;
	  if (elem->type == 'c')
	    change_checkbox(mouse_pos, list, elem);
	  if (elem->type == 't')
	    change_textbox(mouse_pos, list, elem);
	  if (elem->type == 'b')
	    change_button(mouse_pos, list, elem);
	  list = list->next;
	}
      is_pass = 0;
    }
}
