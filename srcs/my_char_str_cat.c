/*
** my_char_str_cat.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:45:26 2016 
** Last update Sat Feb 27 08:46:05 2016 
*/

#include "tekgui.h"

char		*my_char_str_cat(char *str, char l)
{
  char		*new_str;
  int		i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
    return (0);
  while (*str)
    {
      new_str[i] = *str;
      str++;
      i++;
    }
  new_str[i] = l;
  i++;
  new_str[i] = '\0';
  return (new_str);
}
