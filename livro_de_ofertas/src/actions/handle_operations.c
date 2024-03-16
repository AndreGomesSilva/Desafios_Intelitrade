
#include "../../include/offer_book.h"

int	handle_operations(t_book **book, t_property *property)
{
	t_book	*node_in_position;
  int     success;

  success = FALSE;
	if (book && *book == NULL)
  {
    if (!init_book(book))
	  	return (success);
  }
	node_in_position = get_node_position(*book, property->position);
	if (property->action == INSERT && !node_in_position)
  {
		if (insert_property(*book, property))
      success = TRUE;
  }
	else if ((property->action == MODIFIER || property->action == INSERT) && node_in_position)
  {
		if (modify_property(node_in_position, property))
      success = TRUE;
  }
	else if (property->action == DELETE)
  {
		if (delete_property(node_in_position) != node_in_position)
      success = TRUE;
  }
  return (success);
}
