/*
** teklettre.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:51:29 2016 
** Last update Sat Feb 27 08:51:56 2016 
*/

#include "tekgui.h"

void			teklettre(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *img,
				  t_bunny_position *pos,
				  char lettre)
{
  img->clipable.clip_x_position = lettre * 5;
  img->clipable.clip_y_position = 0;
  blit_tektext(pix, img, pos);
}
