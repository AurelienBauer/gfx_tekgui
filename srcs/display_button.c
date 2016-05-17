/*
** display_button.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:40:19 2016 
** Last update Sat Feb 27 11:19:02 2016 
*/

#include "tekgui.h"

int                     display_button(t_bunny_pixelarray *pix,
                                       t_bunny_pixelarray *img, t_elem *elem)
{
  t_bunny_square        button;

  if (elem->is_check == 1)
    {
      button.pos.x = elem->pos.x - 3;
      button.pos.y = elem->pos.y - 3;
      button.width = elem->width + 6;
      button.height = elem->height + 6;
      square(pix, &button, BLACK);
      elem->is_check = 0;
    }
  button.pos = elem->pos;
  button.width = elem->width;
  button.height = elem->height;
  square(pix, &button, elem->color);
  button.pos.x = button.pos.x + (elem->width / 2)
    - (my_strlen(elem->text) * 3);
  button.pos.y = button.pos.y + (elem->height / 2) - 4;
  make_text(pix, img, elem->text, button.pos);
}
