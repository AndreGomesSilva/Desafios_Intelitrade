
#include "../../include/offer_book.h"

static void free_book(t_book *book)
{
  if (book == NULL)
    return;
  if (book != NULL)
  {
    free_book(book->next);
    free(book);
  }
}

void handle_free(t_book *book, t_property *property)
{
  free_book(book);
  free(property);
}
