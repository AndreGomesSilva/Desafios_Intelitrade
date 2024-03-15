
#include "../../include/offer_book.h"

void reduce_position(t_book *book)
{
  t_book *node;

  node = book;
  while (node != NULL)
  {
    node->position = node->position - 1;
    node = node->next;
  }
}

int position_exists(t_book *book, int position)
{
  t_book  *node;
  int     found;

  node = book;
  found = FALSE;
  while (node != NULL && !found)
  {
    if (node->position == position)
      found = TRUE;
    else
      node = node->next;
  }
  return found;
}

t_book *new_node_book(t_book *book)
{
  t_book *temp_node;
  t_book *new_node;
  
  temp_node = book;
  while (temp_node->next != NULL)
    temp_node = temp_node->next;
  new_node = (t_book *) calloc(1, sizeof(t_book));
  if (new_node != NULL)
  {
    new_node->next = NULL;
    new_node->position = temp_node->position + 1;
    temp_node->next = new_node;
    return new_node;
  }
  else
    return NULL;
}

int init_book(t_book *book)
{
  t_book *node;

  node = (t_book *) calloc(1, sizeof(t_book));
  if (node != NULL)
  {
    node->next = NULL;
    node->position = 1;
    *book = *node;
    return TRUE;
  }
  else
    return FALSE;
}

int new_book(t_book *book)
{
  if (book == NULL)
  {
    if (init_book(book))
      return TRUE;
    else
      return FALSE;
  }
  else
    return FALSE;
}
