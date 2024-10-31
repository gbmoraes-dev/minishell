/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:05 by gamoraes          #+#    #+#             */
/*   Updated: 2024/10/31 19:35:20 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	while (*string)
	{
		if (*string == character)
			return ((char *) string);
		string++;
	}
	if (*string == character)
		return ((char *) string);
	return (0);
}
