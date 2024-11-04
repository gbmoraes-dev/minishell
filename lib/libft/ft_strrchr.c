/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:42:55 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:52 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	int	length;

	length = ft_strlen(string);
	while (length >= 0)
	{
		if (string[length] == character)
			return ((char *) string + length);
		length--;
	}
	return (0);
}
