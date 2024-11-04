/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:46 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/19 15:51:41 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int character, size_t length)
{
	unsigned char	*aux;

	aux = (unsigned char *) string;
	while (length-- > 0)
		*aux++ = (unsigned char) character;
	return (string);
}
