/******************************************************************************
* Nome do Arquivo: ft_strlen.c                                                *
*                                                                             *
* Autor: André Gomes                                                          *
*                                                                             *
* Data: 13/03/2024                                                            *
******************************************************************************/

#include "../include/offer_book.h"

int ft_strlen(const char *str)
{
  int i;

  if (!str || !*str)
    return 0;
  i = 0;
  while (str[i])
    i++;
  return i;
}
