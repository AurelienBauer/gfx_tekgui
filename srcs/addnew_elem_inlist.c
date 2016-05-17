/*
** addnew_elem_inlist.c for  in /home/aurelien/rendu/IGRAPH/gfx_tekgui/lib/my
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Feb  8 11:05:20 2016 Aurélien
** Last update Mon Feb  8 11:34:14 2016 Aurélien
*/

#include <stdlib.h>

typedef struct          s_list
{
  void                  *data;
  struct s_list		*next;
}                       t_list;

t_list			*addnew_elem_inlist(t_list *list, void *data)
{
  t_list		*new_list;
  t_list		*tmp_list;

  tmp_list = list;
  if ((new_list = malloc(sizeof(*list))) == NULL)
    exit (1);
  new_list->data = data;
  new_list->next = NULL;
  if (list == NULL)
    return (new_list);
  while (tmp_list->next != NULL)
    tmp_list = tmp_list->next;
  tmp_list->next = new_list;
  return (list);
}
