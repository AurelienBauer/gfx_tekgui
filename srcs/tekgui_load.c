/*
** tekgui_load.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb  6 15:05:20 2016 
** Last update Sat Feb 27 23:09:18 2016 
*/

#include "tekgui.h"

void			ram_function(char *buffer)
{
  buffer = buffer + 4;
  set_max_heap_size(my_getnbr(buffer));
}

t_list                  *it_s_button(t_list *list, char *buffer)
{
  t_elem                *new_but;
  char                  **elem;

  elem = my_str_to_wordchar(buffer, ',');
  elem[0] = elem[0] + 2;
  if ((new_but = bunny_malloc(sizeof(t_elem) * 1)) == NULL)
    exit (1);
  new_but->type = 'b';
  new_but->pos.x = my_getnbr(elem[0]);
  new_but->pos.y = my_getnbr(elem[1]);
  new_but->width = my_getnbr(elem[2]);
  new_but->height = my_getnbr(elem[3]);
  new_but->color = my_getnbr(elem[4]);
  new_but->text = elem[5];
  new_but->name_fonction = elem[6];
  new_but->is_check = 0;
  return (addnew_elem_inlist(list, (void*)new_but));
}

t_list                  *it_s_checkbox(t_list *list, char *buffer)
{
  t_elem	        *new_checkbox;
  char                  **elem;

  elem = my_str_to_wordchar(buffer, ',');
  elem[0] = elem[0] + 2;
  if ((new_checkbox = bunny_malloc(sizeof(t_elem) * 1)) == NULL)
    exit (1);
  new_checkbox->type = 'c';
  new_checkbox->pos.x = my_getnbr(elem[0]);
  new_checkbox->pos.y = my_getnbr(elem[1]);
  new_checkbox->width = my_getnbr(elem[2]);
  new_checkbox->height = my_getnbr(elem[3]);
  new_checkbox->color = my_getnbr(elem[4]);
  new_checkbox->is_check = my_getnbr(elem[5]);
  return (addnew_elem_inlist(list, (void*)new_checkbox));
}

t_list                  *it_s_textbox(t_list *list, char *buffer)
{
  t_elem	        *new_textbox;
  char                  **elem;

  elem = my_str_to_wordchar(buffer, ',');
  elem[0] = elem[0] + 2;
  if ((new_textbox = bunny_malloc(sizeof(t_elem) * 1)) == NULL)
    exit (1);
  new_textbox->type = 't';
  new_textbox->pos.x = my_getnbr(elem[0]);
  new_textbox->pos.y = my_getnbr(elem[1]);
  new_textbox->width = my_getnbr(elem[2]);
  new_textbox->height = my_getnbr(elem[3]);
  new_textbox->color = my_getnbr(elem[4]);
  new_textbox->is_check = 0;
  new_textbox->text = elem[5];
  return (addnew_elem_inlist(list, (void*)new_textbox));
}

t_tekgui		*tekgui_load(char *file)
{
  t_tekgui	        *tekgui;
  int			id;
  char			*buffer;

  id = fs_open_file(file);
  if ((tekgui = bunny_malloc(sizeof(t_tekgui) * 1)) == NULL)
    exit (1);
  tekgui->list = NULL;
  while ((buffer = get_next_line(id)) != NULL)
    {
      if(buffer[0] == 'R')
	ram_function(buffer);
      if (buffer[0] == 'b')
	tekgui->list = it_s_button(tekgui->list, buffer);
      if (buffer[0] == 'c')
	tekgui->list = it_s_checkbox(tekgui->list, buffer);
      if (buffer[0] == 't')
	tekgui->list = it_s_textbox(tekgui->list, buffer);
    }
  return (tekgui);
}
