/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:48 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:16:42 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup("", 0));
	if ((start + len) > lens)
		len = lens - start;
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	ft_memmove(str, &((char *)s)[start], len);
	return (str);
}
