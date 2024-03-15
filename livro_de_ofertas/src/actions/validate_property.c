
#include "../../include/offer_book.h"

int validate_property(t_property *property)
{
  if (property->action > 2 || property->action < 0
  || property->quantity < 0
  || property->position < 1
  || property->value < 0)
    return FALSE;
  return TRUE;
}
