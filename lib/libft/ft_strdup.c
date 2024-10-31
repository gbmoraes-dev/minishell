/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:34:33 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/23 16:54:24 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	length;
	size_t	count;
	char	*dest;

	length = ft_strlen(string);
	dest = (char *)ft_calloc((length + 1), sizeof(char));
	if (!dest)
		return (NULL);
	count = 0;
	while (count < length + 1)
	{
		dest[count] = string[count];
		count++;
	}
	return (dest);
}
