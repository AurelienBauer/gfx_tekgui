/*
** fs_open_file.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Dec  1 10:35:30 2015 Aurélien
** Last update Sat Feb 27 10:26:16 2016 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	my_printf(const char *str, ...);

int	fs_open_file(char *filepath)
{
  int	inode;
  if ((inode = open(filepath, O_RDONLY)) == -1)
    {
      write(1, "FAILURE : open file\n", 20);
      exit(1);
    }
  return (inode);
}
