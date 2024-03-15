
#include "../../include/offer_book.h"

void print_book(t_book *book)
{
  t_book *node;
  if (book == NULL)
    return;
  node = book;
  printf("posicao, ação, valor, quantidade\n");
  while (node != NULL)
  {
    printf("%d,%lf,%d\n", node->position, node->value, node->quantity);
    node = node->next;
  }
}
