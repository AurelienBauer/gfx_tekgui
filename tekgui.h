/*
** tekpaint.h for  in /home/thomas/Documents/epitech/gfx_tekpaint
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Jan 25 10:53:54 2016 thomas
** Last update Sun Feb 28 15:22:31 2016 
*/

#ifndef __TEKGUI_H__
# define __TEKGUI_H__

#include "lapin.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <dlfcn.h>

# define DEGREES_TO_RADIANS(angleDegrees) (angleDegrees * M_PI / 180.0)

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_bunny_square
{
  t_bunny_position	pos;
  int			width;
  int			height;
}			t_bunny_square;

typedef struct		s_elem
{
  char			type;
  t_bunny_position	pos;
  unsigned int		width;
  unsigned int		height;
  int			color_text;
  int			color;
  char			*text;
  char			*name_fonction;
  bool			is_check;
}			t_elem;

typedef struct		s_tekgui
{
  t_bunny_window	*win;
  t_bunny_pixelarray   	*pix;
  t_bunny_pixelarray	*img;
  t_list		*list;
}			t_tekgui;

int			my_strlen(char *str);
int			my_getnbr(char  *str);
int			fs_open_file(char *filepath);
char			*get_next_line(const int fd);
char			**my_str_to_wordtab(char *str);
char			**my_str_to_wordchar(char *str, char ch);
t_list                  *addnew_elem_inlist(t_list *list, void *data);
t_list                  *it_s_checkbox(t_list *list, char *buffer);
void			ram_function(char *buffer);

/*
***
tekgui_load
***
*/
t_tekgui		*tekgui_load(char *file);
t_list			*it_s_button(t_list *list, char *buffer);

/*
***
tekpixel.c
***
*/
void                    tekpixel(t_bunny_pixelarray *pix,
                                 t_bunny_position *position,
                                 unsigned int color);

/*
***
display_elem.c
***
*/
int                     display_elem(t_bunny_pixelarray *pix,
				     t_bunny_pixelarray *img,
				     t_list *list);
int                     display_button(t_bunny_pixelarray *pix,
				       t_bunny_pixelarray *img,
				       t_elem *elem);
int                     display_checkbox(t_bunny_pixelarray *pix,
					 t_elem *elem);
int                     display_textbox(t_bunny_pixelarray *pix,
					t_bunny_pixelarray *img, t_elem *elem);

/*
***
square.c
***
*/
void                    square(t_bunny_pixelarray *pix,
                               t_bunny_square *squ,
                               unsigned int color);
void                    square_xn_yn(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);
void                    square_xn_yp(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);
void                    square_xp_yn(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);
void                    square_xp_yp(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

/*
***
circle.c
***
*/
void                    my_set_circle(t_bunny_pixelarray *pix,
                                      t_bunny_position *origin,
                                      double radius,
                                      unsigned int color);

/*
***
mouse_pos.c
***
*/
void			change_checkbox(const t_bunny_position *mouse_pos,
                                t_list *list, t_elem *elem);
void			mouse(const t_bunny_position *mouse_pos, t_list *list);

/*
***
text.c
***
*/
unsigned int		get_pixel(t_bunny_pixelarray *buffer, int x, int y);
void                    blit_tektext(t_bunny_pixelarray *background,
                                     t_bunny_pixelarray *buffer,
                                     t_bunny_position *pos);
void                    teklettre(t_bunny_pixelarray *pix,
                                  t_bunny_pixelarray *img,
                                  t_bunny_position *pos,
                                  char lettre);
void                    make_text(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *img,
				  char *text, t_bunny_position pos);
/*
***
kayboard.c
***
*/
void			keyboard(t_bunny_event_state sta, t_bunny_keysym sym, t_list *list);
char			*my_char_str_cat(char *str, char l);
char			*my_suppr_char_in_str(char *str);
void			print_key(t_list *list, char lettre);

/*
***
anex_fonction.c
***
*/
int			my_returnlen(char *str);
int			my_backnlen(char *str);
void                    init_plan(t_bunny_pixelarray *pix, int color);

/*
***
tekgui_display.c
***
*/
t_bunny_response        main_loop(void *data);
t_bunny_response        on_click(t_bunny_event_state sta,
                                 t_bunny_mouse_button   but, void *dat);
t_bunny_response        key_board(t_bunny_event_state              sta,
                                  t_bunny_keysym                   sym,
                                  void                             *dat);
void                    tekgui_display(t_bunny_pixelarray *pix,
                                       t_tekgui *gui);
void			*tekfunction(const char *funcname);

#endif
