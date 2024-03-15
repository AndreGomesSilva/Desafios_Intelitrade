/******************************************************************************
* Nome do Arquivo: ft_atoi.c                                                  *
*                                                                             *
* Autor: André Gomes                                                          *
*                                                                             *
* Data: 13/03/2024                                                            *
******************************************************************************/

#include "../include/offer_book.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sing;

	sing = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing *= -1;
		++str;
	}
	if (*str == '+' || *str == '-')
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		++str;
	}
	return (number * sing);
}
