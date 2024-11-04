/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:46:46 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/20 12:51:04 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int character, size_t length)
{
	unsigned char	*string_char;
	unsigned char	tofind;

	string_char = (unsigned char *) string;
	tofind = (unsigned char) character;
	while (length-- > 0)
	{
		if (*string_char == tofind)
			return ((void *) string_char);
		string_char++;
	}
	return (0);
}
