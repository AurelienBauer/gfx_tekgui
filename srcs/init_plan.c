/*
** init_plan.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 09:03:57 2016 
** Last update Sat Feb 27 09:04:23 2016 
*/

#include "tekgui.h"

void                    init_plan(t_bunny_pixelarray *pix, int color)
{
  t_bunny_square        squar;

  squar.pos.x = 0;
  squar.pos.y = 0;
  squar.width = pix->clipable.buffer.width;
  squar.height = pix->clipable.buffer.height;
  square(pix, &squar, color);
}
