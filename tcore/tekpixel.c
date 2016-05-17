/*
** my_set_pixels.c for  in /home/bauer_b/rendu/gfx_colle_fantasy1/exo_3
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Fri Jan 22 10:33:43 2016 Aurélien BAUER
** Last update Sun Feb 28 16:37:12 2016 
*/

#include "lapin.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *position,
				 t_color *color)
{
  t_color	*pixels;

  pixels = ((t_color*)pix->pixels);
  pixels[position->x + position->y * pix->clipable.clip_width].full = color;
}
