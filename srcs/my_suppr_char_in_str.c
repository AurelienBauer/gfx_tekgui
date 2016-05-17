/*
** my_suppr_char_in_str.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:47:06 2016 
** Last update Sat Feb 27 08:47:44 2016 
*/

#include "tekgui.h"

char		*my_suppr_char_in_str(char *str)
{
  str[my_strlen(str) - 1] = '\0';
  return (str);
}
