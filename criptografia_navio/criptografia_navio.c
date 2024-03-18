#include <stdio.h>
#include <stdlib.h>

int	is_byte(char *c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c[i] != '0' && c[i] != '1')
		{
			return (0);
		}
		i++;
	}
	if (c[i] != '\0')
		return (0);
	return (1);
}

int	is_valid_message(char **argv)
{
	int	i;
	int	valid;

	valid = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (is_byte(argv[i]))
			valid = 1;
		else
		{
			valid = 0;
			break ;
		}
		i++;
	}
	return (valid);
}

int	convert_string_byte_to_decimal(char *str)
{
	int	i;
	int	decimal;

	i = 0;
	decimal = 0;
	while (str[i] != '\0')
	{
		decimal = decimal * 2 + str[i] - '0';
		i++;
	}
	return (decimal);
}

char	*invert_two_last_bits(char *str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (i == 6 || i == 7)
		{
			if (str[i] == '0')
				str[i] = '1';
			else
				str[i] = '0';
		}
		i++;
	}
	return (str);
}

char	*swap_half_byte(char *str)
{
	char	first_four_bits[5];
	char	last_four_bits[5];
	int		i;

	i = 0;
	while (i < 4)
	{
		first_four_bits[i] = str[i];
		last_four_bits[i] = str[i + 4];
		str[i] = last_four_bits[i];
		str[i + 4] = first_four_bits[i];
		i++;
	}
	return (str);
}

void	decryptor(char **message)
{
	int		i;
	char	decimal;
	char	*aux;

	i = 0;
	while (message[i] != NULL)
	{
		aux = invert_two_last_bits(message[i]);
		aux = swap_half_byte(aux);
		decimal = convert_string_byte_to_decimal(aux);
		printf("%c", decimal);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (is_valid_message(&argv[1]))
			decryptor(&argv[1]);
		else
		{
			fprintf(stderr, "Error: Mensagem inválida\n");
			exit(1);
		}
	}
	else
	{
		fprintf(stderr, "Error: Quantidade de argumentos insuficiente\n");
		exit(1);
	}
	return (0);
}
