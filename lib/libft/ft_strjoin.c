/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:02:32 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/05 04:02:41 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	totalsize;

	if (!s1 || !s2)
		return (NULL);
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)ft_calloc((totalsize + 1), sizeof(char));
	if (!strjoin)
		return (NULL);
	while (s1 && *s1 != '\0')
		*strjoin++ = *s1++;
	while (s2 && *s2 != '\0')
		*strjoin++ = *s2++;
	*strjoin = '\0';
	return ((strjoin - totalsize));
}
