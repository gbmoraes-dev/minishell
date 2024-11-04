/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:05 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:15:57 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	char	ch;
	int		len;
	int		i;

	i = 0;
	len = 1 + ft_strlen(string);
	ch = ((char)character);
	while (i < len)
	{
		if (*string == ch)
			return ((char *)string);
		string++;
		i++;
	}
	return (NULL);
}
