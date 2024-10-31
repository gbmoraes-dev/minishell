/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:10:05 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/07 14:20:20 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	size_t	length;
	char	*strmapi;

	if (!s || !f)
		return (NULL);
	count = 0;
	length = ft_strlen(s);
	strmapi = (char *)ft_calloc(length + 1, sizeof(char));
	if (!strmapi)
		return (NULL);
	strmapi[length] = '\0';
	while (count < length)
	{
		strmapi[count] = (*f)(count, s[count]);
		count++;
	}
	return (strmapi);
}
