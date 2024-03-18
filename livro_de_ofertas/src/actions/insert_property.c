#include "../../include/offer_book.h"

static int	set_propety(t_book *node, t_property *property)
{
	if (property->position > 0)
	{
		if (node->value == 0 && node->quantity == 0)
		{
			node->value = property->value;
			node->quantity = property->quantity;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_book	*insert_property(t_book *book, t_property *property)
{
	t_book	*node;

	if (book->position == 0)
	{
		book->position = 1;
		node = modify_property(book, property);
	}
	else
	{
    node = add_node_book(book);
    if (node)
      set_propety(node, property);
	}
  return (node);
}
