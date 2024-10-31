/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:43 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/23 16:43:29 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t length)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;
	size_t	j;

	if (!dest && !length)
		return (0);
	dsize = ft_strlen(dest);
	ssize = ft_strlen(src);
	i = dsize;
	j = 0;
	while ((i < length - 1) && (src[j]) && (length > 0))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (length < i)
		return (ssize + length);
	return (ssize + dsize);
}
