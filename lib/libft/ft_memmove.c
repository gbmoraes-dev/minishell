/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:55 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:17:35 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src == dst || len == 0)
		return ((char *)dst);
	if (src > dst)
	{
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	return ((char *)dst);
}
