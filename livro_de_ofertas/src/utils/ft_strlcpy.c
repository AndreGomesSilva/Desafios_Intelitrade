/******************************************************************************
* Nome do Arquivo: ft_strlcpy.c                                                *
*                                                                             *
* Autor: André Gomes                                                          *
*                                                                             *
* Data: 13/03/2024                                                            *
******************************************************************************/

#include "../include/offer_book.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{	
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*(src + i) && --size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (len);
}
