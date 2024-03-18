#include "../../include/offer_book.h"

void print_book(t_book *book)
{
  t_book *node;
  printf("| POSICAO |  VALOR  | QUANTIDADE |\n");
  printf("|---------|---------|------------|\n");
  if (book == NULL)
    return;
  node = book;
  while (node != NULL)
  {
    printf(" %d        |  %.2lf   |  %d      \n", node->position, node->value, node->quantity);
    node = node->next;
  }
  printf("\n");
}
