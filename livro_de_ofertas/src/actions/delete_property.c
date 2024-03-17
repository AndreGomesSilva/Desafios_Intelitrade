
#include "../../include/offer_book.h"

t_book *delete_property(t_book **book, t_book *node)
{
  t_book *next_node;

  next_node = remove_node_book(book, node);
  if (next_node)
    reduce_position(next_node);
  return (next_node);
}
