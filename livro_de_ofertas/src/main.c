/******************************************************************************
 * Nome do Arquivo: offer_book.c                                               *
 *                                                                             *
 * Autor: André Gomes                                                          *
 *                                                                             *
 * Data: 13/03/2024                                                            *
 ******************************************************************************/

#include "../include/offer_book.h"

int	get_notifications(int *number_notification, t_property *property)
{
	char	buffer[100];
	int		number;

	printf("posicao, ação, valor, quantidade\n");
	fgets(buffer, sizeof(buffer), stdin);
	number = sscanf(buffer, "%d,%d,%lf,%d", &property->position,
			&property->action, &property->value, &property->quantity);
	if (number == 4 && validate_property(property))
		return (TRUE);
	else
	{
		printf("Formato de entrada inválido,\nexemplo de formato valido: 1,0,100.00,10\ngostaria de tentar novamente? (você continuará do ultimo lancamento)\ndigite S para sim ou N para não\n");
		while (TRUE)
		{
			fgets(buffer, sizeof(buffer), stdin);
			if (buffer[0] == 'S' || buffer[0] == 's')
			{
				*number_notification = *number_notification + 1;
				return (FALSE);
			}
			else if (buffer[0] == 'N' || buffer[0] == 'n')
			{
				printf("ate mais!\n");
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

int	get_number_notifications(int *number_notification)
{
	char	buffer[100];

	printf("Bem vindo ao Livro de Ofertas!\n");
	printf("Quantas operações deseja executar?\n");
	fgets(buffer, sizeof(buffer), stdin);
	if (sscanf(buffer, "%d", number_notification) != 1)
	{
		printf("Formato de entrada inválido,\n");
		return (FALSE);
	}
	return (TRUE);
}

int	main(void)
{
	t_property	*property;
	t_book		*book;
	int			number_notification;

	property = (t_property *)calloc(1, sizeof(t_property));
	book = NULL;
	number_notification = 0;
	if (get_number_notifications(&number_notification))
	{
		for (int i = 0; i < number_notification; i++)
		{
			if (get_notifications(&number_notification, property))
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
	}
	else
		printf("Error: falha ao ler o número de notificações!\n");
	handle_free(book, property);
	return (0);
}
