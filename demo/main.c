/*
** main.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb  6 14:53:02 2016 
** Last update Sat Feb 27 10:03:09 2016 
*/

#include "tekgui.h"

int			main(int argn, char **argv)
{
  t_tekgui		*tekgui;
  t_bunny_pixelarray	*pix;

  tekgui = tekgui_load(argv[1]);
  if ((pix = bunny_new_pixelarray(920, 640)) == NULL)
    return (0);
  tekgui_display(pix, tekgui);
  return (0);
}
