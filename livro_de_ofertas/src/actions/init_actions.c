
#include "../../include/offer_book.h"

void	init_actions(t_property *property, t_book *book)
{
	if (book == NULL)
		if (!new_book(book))
      return;
	if (property->action == INSERT)
		insert_property(book, property);
	// else if (property->action == MODIFIER)
	// 	modify_property(book, property);
	// else if (property->action == DELETE)
	// 	delete_property(book, property);
}
