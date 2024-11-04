/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:34:33 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 19:40:26 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1, int flag)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = 0;
	while (len-- > 0)
		ptr[len] = s1[len];
	if (flag && s1)
		free(s1);
	return (ptr);
}
