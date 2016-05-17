/*
** print_key.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:48:55 2016 
** Last update Sat Feb 27 08:49:44 2016 
*/

#include "tekgui.h"

void		print_key(t_list *list, char lettre)
{
  t_elem	*elem;

  while (list != NULL)
    {
      elem = (t_elem*)list->data;
      if (elem->type == 't')
	{
	  if (elem->is_check == 1)
	    {
	      if (lettre == -100)
		my_suppr_char_in_str(elem->text);
	      else
		{
		  if ((my_backnlen(elem->text) * 7) < elem->height - 20)
		    elem->text = my_char_str_cat(elem->text, lettre);
		}
	    }
	}
      list = list->next;
    }
}
