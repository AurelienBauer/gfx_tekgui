/*
** text.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Mon Feb 22 16:09:00 2016 
** Last update Sat Feb 27 10:39:22 2016 
*/

#include "lapin.h"

unsigned int	        get_pixel(t_bunny_pixelarray *buffer,
				  int x,
				  int y)
{
  unsigned int		color;
  unsigned int		i;

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

void			teklettre(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *img,
				  t_bunny_position *pos,
				  char lettre)
{
  img->clipable.clip_x_position = lettre * 5;
  img->clipable.clip_y_position = 0;
  blit_tektext(pix, img, pos);
}

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png)
{
  t_bunny_position	posi;

  posi.x = 0
  posi.y = 0
  while (*str)
    {
      teklettre(out, fontpng, &posi, *str);
      str++;
      posi.x = posi.x + 6;
    }
}
