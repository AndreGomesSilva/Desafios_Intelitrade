#include "../../include/offer_book.h"

t_book *remove_node_book(t_book **book, t_book *node)
{
  t_book *previous_node;
  t_book *next_node;

  next_node = NULL;
  if (node)
  {
    previous_node = node->previous;
    next_node = node->next;
    if (previous_node)
      previous_node->next = next_node;
    if (next_node)
      next_node->previous = previous_node;
    if (*book == node)
      *book = next_node;
    free(node);
  }
  return (next_node);
}

void reduce_position(t_book *node)
{
  while (node != NULL)
  {
    node->position = node->position - 1;
    node = node->next;
  }
}

t_book *get_node_position(t_book *book, int position)
{
  t_book  *node;
  t_book  *found_node;

  node = book;
  found_node = NULL;
  while (node != NULL && !found_node)
  {
    if (node->position == position)
      found_node = node;
    else
      node = node->next;
  }
  return found_node;
}

t_book *add_node_book(t_book *book)
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
    new_node->previous = temp_node;
    return new_node;
  }
  else
    return NULL;
}

int init_book(t_book **book)
{
  t_book *node;
  node = (t_book *) calloc(1, sizeof(t_book));
  if (node != NULL)
  {
    node->next = NULL;
    node->previous = NULL;
    node->position = 0;
    *book = node;
    return TRUE;
  }
  else
    return FALSE;
}
