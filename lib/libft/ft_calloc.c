/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:00:50 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:06:30 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;
	int		i;

	n = nmemb * size;
	i = n;
	ptr = malloc(n);
	if (ptr == NULL)
		return (NULL);
	while (i-- > 0)
		((char *)ptr)[i] = 0;
	return (ptr);
}
