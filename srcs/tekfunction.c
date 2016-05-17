/*
** tekfunction.c for  in /home/tek/rendu/gfx_tekgui/tcore
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 10:40:37 2016 
** Last update Sat Feb 27 12:17:08 2016 
*/

#include "tekgui.h"
#define _GNU_SOURCE

void		*tekfunction(const char *funcname)
{
  void		*handle;
  void		*pnt;

  if ((handle = dlopen(NULL, RTLD_LAZY)) == NULL)
    return (NULL);
  if ((pnt = dlsym(handle, funcname)) == NULL)
    return (NULL);
  dlclose(handle);
  return (pnt);
}
