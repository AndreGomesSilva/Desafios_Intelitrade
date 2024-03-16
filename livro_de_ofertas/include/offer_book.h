/******************************************************************************
 * Nome do Arquivo: offer_book.h                                               *
 *                                                                             *
 * Autor: André Gomes                                                          *
 *                                                                             *
 * Data: 13/03/2024                                                            *
 ******************************************************************************/

#ifndef OFFER_BOOK_H
# define OFFER_BOOK_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

enum				e_action
{
	INSERT = 0,
	MODIFIER,
	DELETE,
};

typedef struct s_property
{
	int				position;
	int				action;
	double			value;
	int				quantity;
}					t_property;

typedef struct s_book
{
	int				position;
	double			value;
	int				quantity;
	struct s_book	*next;
	struct s_book	*previous;
}					t_book;

// book
void				reduce_position(t_book *node);
t_book				*remove_node_book(t_book *node);
t_book				*get_node_position(t_book *book, int position);
t_book				*add_node_book(t_book *book);
int					init_book(t_book **book);

// actions
t_book				*delete_property(t_book *node);
t_book				*modify_property(t_book *node, t_property *property);
t_book				*insert_property(t_book *book, t_property *property);
int					handle_operations(t_book **book, t_property *property);
int					validate_property(t_property *property);

// utils
void				print_book(t_book *book);

// handle_free
void				handle_free(t_book *book, t_property *property);

#endif
