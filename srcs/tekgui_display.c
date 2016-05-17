/*
** tekgui_display.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Fri Feb 26 19:44:07 2016 
** Last update Fri Feb 26 19:48:58 2016 
*/

#include "tekgui.h"

t_bunny_response        on_click(t_bunny_event_state sta,
                                 t_bunny_mouse_button   but, void *dat)
{
  return (GO_ON);
}

t_bunny_response        key_board(t_bunny_event_state              sta,
                                  t_bunny_keysym                   sym,
                                  void                             *data)
{
  t_tekgui              *tekgui;

  tekgui = (t_tekgui*)data;
  keyboard(sta, sym, tekgui->list);
  return (GO_ON);
}

t_bunny_response        main_loop(void *data)
{
  t_tekgui              *tekgui;

  tekgui = (t_tekgui*)data;
  init_plan(tekgui->pix, WHITE);
  mouse(bunny_get_mouse_position(), tekgui->list);
  bunny_set_click_response(&on_click);
  bunny_set_key_response(&key_board);
  display_elem(tekgui->pix, tekgui->img, tekgui->list);
  bunny_blit(&tekgui->win->buffer, &tekgui->pix->clipable, NULL);
  bunny_display(tekgui->win);
  return (GO_ON);
}

void                    tekgui_display(t_bunny_pixelarray *pix,
                                       t_tekgui *gui)
{
  gui->pix = pix;
  bunny_set_loop_main_function(main_loop);
  if ((gui->win = bunny_start(pix->clipable.buffer.width,
			      pix->clipable.buffer.height, 0, "TekGUI")) == NULL)
    exit (1);
  if ((gui->img = bunny_load_pixelarray("font.png")) == NULL)
    exit (1);
  bunny_set_click_response(&on_click);
  bunny_set_key_response(&key_board);
  bunny_loop(gui->win, 50, (void*)gui);
  bunny_delete_clipable(&gui->pix->clipable);
  bunny_stop(gui->win);
}
