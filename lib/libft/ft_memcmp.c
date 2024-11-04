/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:39:47 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/23 15:57:43 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t length)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			count;

	aux1 = (unsigned char *) s1;
	aux2 = (unsigned char *) s2;
	count = 0;
	if (length == 0)
		return (0);
	while (count < length)
	{
		if (aux1[count] != aux2[count])
			return (aux1[count] - aux2[count]);
		count++;
	}
	return (0);
}
