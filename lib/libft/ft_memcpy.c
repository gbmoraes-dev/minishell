/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:05 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/18 15:23:53 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	char	*dest_char;
	char	*src_char;

	dest_char = (char *) dest;
	src_char = (char *) src;
	if (!dest_char && !src_char)
		return (dest);
	while (length-- > 0)
		*dest_char++ = *src_char++;
	return (dest);
}
