/*
** display_checkbox.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:41:46 2016 
** Last update Sat Feb 27 08:57:09 2016 
*/

#include "tekgui.h"

int			display_checkbox(t_bunny_pixelarray *pix, t_elem *elem)
{
  t_bunny_square	check;
  t_bunny_position	circlepos;

  check.pos = elem->pos;
  check.width = elem->width;
  check.height = elem->height;
  square(pix, &check, elem->color);
  if (elem->is_check == 1)
    {
      circlepos.x = elem->pos.x + elem->width / 2;
      circlepos.y = elem->pos.y + elem->height / 2;
      my_set_circle(pix, &circlepos, elem->width / 2 - 5, BLACK);
    }
}
