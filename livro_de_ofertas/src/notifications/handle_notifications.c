#include "../../include/offer_book.h"

int	get_notifications(int *number_notification, t_property *property, int *stop_program)
{
	char	buffer[100];
	int		number;

	printf("posicao, ação, valor, quantidade\n");
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
  {
    fprintf(stderr, "Error: Falha ao ler a entrada\n");
    return (FALSE);
  }
	number = sscanf(buffer, "%d, %d, %lf, %d ", &property->position,
			&property->action, &property->value, &property->quantity);
	if (number == 4 && validate_property(property))
		return (TRUE);
	else
	{
		printf("Formato de entrada inválido,\nexemplo de formato valido: 1,0,100.00,10\ngostaria de tentar novamente? (você continuará do ultimo lancamento)\ndigite S para sim ou N para não\n");
		while (TRUE)
		{
			fgets(buffer, sizeof(buffer), stdin);
			if ((buffer[0] == 'S' && buffer[1] == '\n') || (buffer[0] == 's'
					&& buffer[1] == '\n'))
			{
				*number_notification = *number_notification + 1;
				return (FALSE);
			}
			else if ((buffer[0] == 'N' || buffer[0] == 'n' || buffer[0] == 'q'
					|| buffer[0] == 'Q') && buffer[1] == '\n')
			{
        *stop_program = TRUE;
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

int	get_number_notifications(int *number_notification, int *stop_program)
{
	char	buffer[100];
	int		result;

	printf("Caso queira encerrar o programa, digite 'q'\n");
	printf("Quantas operações deseja executar?\n");
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		fprintf(stderr, "Error: Falha ao ler a entrada\n");
		return (FALSE);
	}
	if ((buffer[0] == 'q' && buffer[1] == '\n') || (buffer[0] == 'Q'
			&& buffer[1] == '\n'))
	{
		*stop_program = TRUE;
		return (TRUE);
	}
	if (sscanf(buffer, "%d %n", number_notification, &result) != 1
		|| result != (int)ft_strlen(buffer))
	{
		fprintf(stderr, "Error: Formato de entrada inválido\n");
		return (FALSE);
	}
	return (TRUE);
}
