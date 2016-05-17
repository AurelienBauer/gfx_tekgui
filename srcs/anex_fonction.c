/*
** anex_fonction.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Fri Feb 26 18:06:40 2016 
** Last update Fri Feb 26 19:27:15 2016 
*/

#include <tekgui.h>

void                    init_plan(t_bunny_pixelarray *pix, int color)
{
  t_bunny_square        squar;

  squar.pos.x = 0;
  squar.pos.y = 0;
  squar.width = pix->clipable.buffer.width;
  squar.height = pix->clipable.buffer.height;
  square(pix, &squar, color);
}

int	my_returnlen(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(str);
  while (str[i] != '\n' && i > 0)
    {
      i--;
      j++;
    }
  return (j);
}

int	my_backnlen(char *str)
{
  int	i;

  i = 0;
  while(*str)
    {
      if (*str == '\n')
	i++;
      str++;
    }
  return (i);
}
