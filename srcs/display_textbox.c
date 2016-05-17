/*
** display_textbox.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:42:55 2016 
** Last update Sat Feb 27 08:43:17 2016 
*/

#include "tekgui.h"

int			display_textbox(t_bunny_pixelarray *pix,
					t_bunny_pixelarray *img, t_elem *elem)
{
  t_bunny_square	text;

  if (elem->is_check == 1)
    {
      text.pos.x = elem->pos.x - 3;
      text.pos.y = elem->pos.y - 3;
      text.width = elem->width + 6;
      text.height = elem->height + 6;
      square(pix, &text, BLACK);
    }
  text.pos = elem->pos;
  text.width = elem->width;
  text.height = elem->height;
  square(pix, &text, elem->color);
  if ((my_returnlen(elem->text) * 6) > elem->width - 20)
    elem->text = my_char_str_cat(elem->text, '\n');
  text.pos.x = text.pos.x + 5;
  text.pos.y = text.pos.y + 5;
  make_text(pix, img, elem->text, text.pos);
}
