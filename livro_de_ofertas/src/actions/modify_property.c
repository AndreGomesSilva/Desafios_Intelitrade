
#include "../../include/offer_book.h"

t_book	*modify_property(t_book *node_book, t_property *property)
{
  if (node_book)
  {
    if (property->value > 0)
      node_book->value = property->value;
    if (property->quantity > 0)
      node_book->quantity = property->quantity;
  }
  return (node_book);
}
