/*
** circle.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Fri Feb 19 13:38:39 2016 
** Last update Fri Feb 19 13:57:45 2016 
*/

#include "tekgui.h"


void			my_set_circle(t_bunny_pixelarray *pix,
				      t_bunny_position *origin,
				      double radius,
				      unsigned int color)
{
  double		mini_radius;
  double		angle;
  t_bunny_position	pos;

  angle = 0;
  mini_radius = 1;
  while (mini_radius < radius)
    {
      angle = 0;
      while (angle < 360)
	{
	  pos.x = cos(DEGREES_TO_RADIANS(angle)) * mini_radius + origin->x;
	  pos.y = sin(DEGREES_TO_RADIANS(angle)) * mini_radius + origin->y;
	  if (pos.x > 0 && pos.x < pix->clipable.clip_width &&
	      pos.y > 0 && pos.y < pix->clipable.clip_height)
	    tekpixel(pix, &pos, color);
	  angle += 0.10;
	}
      mini_radius += 0.25;
    }
}
