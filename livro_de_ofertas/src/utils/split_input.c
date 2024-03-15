/******************************************************************************
* Nome do Arquivo: split_input.c                                              *
*                                                                             *
* Autor: André Gomes                                                          *
*                                                                             *
* Data: 13/03/2024                                                            *
******************************************************************************/

#include "../include/offer_book.h"

void free_array(char **array)
{
  int i;

  if (!array)
    return;
  i = 0;
  while (array[i])
  {
    free(array[i]);
    i++;
  }
  free(array);
}

int count_tolkens(char *input, char delimiter)
{
  int iterator;
  int tolkens;

  if (!input || !*input)
    return 0;
  iterator = 0;
  tolkens = 0;
  while (input[iterator])
  {
    if (input[iterator] == delimiter)
      tolkens++;
    iterator++;
  }
  return (tolkens + 1);
}

void split_input_aux(char *input, char delimiter, char **array)
{
  int iterator;
  int index;
  char *token;

  if (!input || !*input || !array)
    return;
  iterator = 0;
  index = 0;
  while (input[iterator])
  {
    if (input[iterator] == delimiter)
    {
      input[iterator] = '\0';
      token = (char *)malloc(sizeof(char) * (iterator + 1));
      if (!token)
        return;
      ft_strlcpy(token, input, iterator + 1);
      array[index++] = token;
    }
    iterator++;
  }
  input[iterator] = '\0';
  token = (char *)malloc(sizeof(char) * (iterator + 1));
  if (!token)
    return;
  ft_strlcpy(token, input, iterator + 1);
  array[index] = token;
}

char **split_input(char *input, char delimiter)
{
  char **array;
  int tolkens;

  if (!input || !*input)
    return NULL;
  tolkens = count_tolkens(input, delimiter);
  array = (char **)malloc(sizeof(char *) * (tolkens + 1));
  if (!array)
    return NULL;
  split_input_aux(input, delimiter, array);
  return array;
}
