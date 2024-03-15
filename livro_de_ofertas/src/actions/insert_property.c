
#include "../../include/offer_book.h"
#include <stdio.h>

static int	new_insert_logic(t_book *book, t_property *property)
{
	if (property->position > 0)
	{
		if (book->value == 0 && book->quantity == 0)
		{
			book->value = property->value;
			book->quantity = property->quantity;
			return (TRUE);
		}
	}
  return (FALSE);
}

t_book	*insert_property(t_book *book, t_property *property)
{
	t_book	*node;

  node = NULL;
	if (position_exists(book, property->position))
  {
    printf("Position %d already exists\n", property->position);
		// node = modify_property(book, property);
  }
	else
	{
		node = new_node_book(book);
    if (node == NULL)
      return (NULL);
    if (new_insert_logic(book, property))
      return (node);
	}
  return (node);
}
