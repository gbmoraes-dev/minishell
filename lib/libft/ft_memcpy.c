/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:05 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:17:55 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	const char	*srcc;
	char		*destc;

	destc = (char *)dest;
	srcc = (const char *)src;
	if (!destc && !srcc)
		return (NULL);
	while (len--)
		*destc++ = *srcc++;
	return (dest);
}
