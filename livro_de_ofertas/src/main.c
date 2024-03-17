
#include "../include/offer_book.h"

int	main(void)
{
	t_property	*property;
	t_book		*book;
	int			number_notification;
  int     stop_program;

	property = (t_property *)calloc(1, sizeof(t_property));
	book = NULL;
	number_notification = 0;
  stop_program = FALSE;
	printf("Bem vindo ao Livro de Ofertas!\n");
  while (stop_program == FALSE)
  {
    if (get_number_notifications(&number_notification, &stop_program))
    {
      for (int i = 0; i < number_notification && stop_program == FALSE; i++)
      {
        if (get_notifications(&number_notification, property, &stop_program))
        {
          if (handle_operations(&book, property))
          {
            printf("Operação concluída!\n");
            print_book(book);
          }
          else
            printf("Operação falhou!\n");
        }
      }
      stop_program = TRUE;
    }
    else
      fprintf(stderr, "Error: Falha ao obter número de notificações!\n");
  }
	printf("\n-----------BOOK_FINAL-------------\n");
	print_book(book);
  printf("\nPrograma encerrado\naté mais!\n"); 
	handle_free(book, property);
	return (0);
}
