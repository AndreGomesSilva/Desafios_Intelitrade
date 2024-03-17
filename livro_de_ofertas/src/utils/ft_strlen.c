
#include "../../include/offer_book.h"

size_t ft_strlen(char *str)
{
  int i;

  i = 0;
  if (str == NULL)
    return (i);
  while (str[i] != '\0')
    i++;
  return (i);
}
