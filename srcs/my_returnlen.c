/*
** my_returnlen.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 09:04:58 2016 
** Last update Sat Feb 27 09:05:32 2016 
*/

#include "tekgui.h"

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
