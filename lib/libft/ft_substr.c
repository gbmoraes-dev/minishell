/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:48 by gamoraes          #+#    #+#             */
/*   Updated: 2024/10/30 22:21:56 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t length)
{
	size_t	sourcelen;
	size_t	substrlen;
	char	*substr;

	if (!string)
		return (NULL);
	sourcelen = ft_strlen(string);
	substrlen = sourcelen - (size_t)start;
	if (start > sourcelen)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (length > sourcelen)
		length = sourcelen - start + 1;
	if (substrlen > length)
		substrlen = length;
	substr = (char *)ft_calloc(substrlen + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (string + start), length + 1);
	return (substr);
}
