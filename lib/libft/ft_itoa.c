/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:01 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/13 01:21:05 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitlen(long int number)
{
	size_t	length;

	length = 0;
	if (number <= 0)
		length++;
	while (number)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int number)
{
	long int	nb;
	size_t		size;
	size_t		index;
	char		*itoa;

	nb = number;
	size = ft_digitlen(number);
	index = size - 1;
	itoa = (char *)ft_calloc((size + 1), sizeof(char));
	if (!itoa)
		return (NULL);
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		itoa[0] = '0';
	while (nb)
	{
		itoa[index--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoa);
}
