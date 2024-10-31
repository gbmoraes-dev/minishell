/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:02:57 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/05 04:02:59 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*strtrim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && (s1[end] == '\0' || ft_strchr(set, s1[end])))
		end--;
	if (!(s1[0] == '\0'))
		end++;
	strtrim = malloc(sizeof(char) * ((end - start) + 1));
	if (!strtrim)
		return (NULL);
	ft_strlcpy(strtrim, s1 + start, end - start + 1);
	return (strtrim);
}
