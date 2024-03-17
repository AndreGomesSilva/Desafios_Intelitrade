
#include "../../include/offer_book.h"

int	handle_operations(t_book **book, t_property *property)
{
	t_book	*node;
  int     success;

  success = FALSE;
	if (book && *book == NULL)
  {
    if (!init_book(book))
	  	return (success);
  }
	node = get_node_position(*book, property->position);
	if (property->action == INSERT && !node)
  {
    printf("inserindo\n");
		if (insert_property(*book, property))
      success = TRUE;
  }
	else if ((property->action == MODIFIER || property->action == INSERT) && node)
  {
    printf("modificando\n");
		if (modify_property(node, property))
      success = TRUE;
  }
	else if (property->action == DELETE && node)
  {
    printf("deletando\n");
		if (delete_property(book, node) != node)
      success = TRUE;
  }
  return (success);
}
