/*
** display_elem.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Thu Feb 18 17:24:03 2016 
** Last update Sat Feb 27 08:43:19 2016 
*/

#include "tekgui.h"

int			display_elem(t_bunny_pixelarray *pix,
				     t_bunny_pixelarray *img, t_list *list)
{
  t_elem		*elem;

  if ((elem = malloc(sizeof(t_elem) * 1000)) == NULL)
    return (0);
  while (list != NULL)
    {
      elem = (t_elem*)list->data;
      if (elem->type == 'b')
	display_button(pix, img, elem);
      if (elem->type == 'c')
	display_checkbox(pix, elem);
      if (elem->type == 't')
	display_textbox(pix, img, elem);
      list = list->next;
    }
}
