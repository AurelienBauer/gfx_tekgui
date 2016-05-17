/*
** anex_fonction.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Fri Feb 26 18:06:40 2016 
** Last update Sat Feb 27 09:16:40 2016 
*/

#include "tekgui.h"

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
