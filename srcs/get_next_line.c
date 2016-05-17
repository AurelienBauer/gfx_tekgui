/*
** get_next_line.c for  in /home/aurelien/rendu/CPE_2015_getnextline
** 
** Made by Aur��lien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Jan  4 13:47:19 2016 Aur��lien
** Last update Thu Feb  4 19:39:18 2016 Aur�lien
*/

#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE (1)

char		*get_next_line(const int fd);
int		my_strlen(char *str);

char		*my_strcatg(char *data, char *add)
{
  int		i;
  char		*dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(data) +
				     my_strlen(add) + 1))) == NULL)
    return (NULL);
  while (*data != '\0')
    {
      dest[i] = *data;
      data++;
      i++;
    }
  while (*add != '\0')
    {
      dest[i] = *add;
      add++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*get_end(char *buffer, char *save, int nbread, const int fd)
{
  free(buffer);
  if (nbread == 0)
    return (NULL);
  if (nbread < READ_SIZE)
    {
      buffer = save;
      save = NULL;
      return (buffer);
    }
  return (get_next_line(fd));
}

char            *get_next_line(const int fd)
{
  static char   *save = "\0";
  char          *buffer;
  int           j;
  int           nbread;

  j = -1;
  if ((buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (save == NULL)
    return (NULL);
  if ((nbread = read(fd, buffer, READ_SIZE)) == -1)
    return (NULL);
  buffer[nbread] = '\0';
  save = my_strcatg(save, buffer);
  while (save[++j] != '\0')
    {
      if (save[j] == '\n')
	{
	  save[j] = '\0';
	  buffer = save;
	  save = &save[j + 1];
	  return (buffer);
	}
    }
  return(get_end(buffer, save, nbread, fd));
}
