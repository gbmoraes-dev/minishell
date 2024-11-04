/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:09:28 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/09 03:14:06 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t length)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)haystack;
	if (*needle == '\0')
		return (s);
	while ((i < length) && (s[i]))
	{
		k = i;
		while (needle[j] && (k < length) && (s[k] == needle[j]))
		{
			if (needle[j + 1] == '\0')
				return (&s[i]);
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
