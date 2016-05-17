/*
** blit_tektext.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:53:16 2016 
** Last update Sat Feb 27 08:53:37 2016 
*/

#include "tekgui.h"

unsigned int    get_pixel(t_bunny_pixelarray *buffer,
                          int x,
                          int y)
{
  unsigned int  color;
  unsigned int  i;

  i = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    return (color = (((t_color*)buffer->pixels)[i].full));
  return (color = 0);
}

void			blit_tektext(t_bunny_pixelarray *background,
				     t_bunny_pixelarray *buffer,
				     t_bunny_position *pos)
{
  t_bunny_position	pos_rela;
  unsigned int		color;

  pos_rela.y = pos->y;
  while (pos_rela.y < 7 + pos->y)
    {
      pos_rela.x = pos->x;
      while (pos_rela.x < 5 + pos->x)
        {
          color = get_pixel(buffer, pos_rela.x +
			    buffer->clipable.clip_x_position - pos->x,
			    pos_rela.y + buffer->clipable.clip_y_position
			    - pos->y);
          if (color != 0)
	    tekpixel(background, &pos_rela, color);
          pos_rela.x++;
        }
      pos_rela.y++;
    }
}
