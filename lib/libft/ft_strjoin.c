/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:02:32 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 19:36:38 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_free(char *s1, char *s2, int flag);
static char	*join_str(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*str;

	str = join_str(s1, s2);
	if (!str)
		return (NULL);
	if (flag)
		check_free(s1, s2, flag);
	return (str);
}

static char	*join_str(char *s1, char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
		return (ft_strdup(s1, 0));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	count = 0;
	str = ft_calloc((i + j + 1), 1);
	if (str == NULL)
		return (NULL);
	while (count < i)
	{
		str[count] = s1[count];
		count++;
	}
	while (--j >= 0)
		str[count + j] = s2[j];
	return (str);
}

static void	check_free(char *s1, char *s2, int flag)
{
	if (flag == 1)
	{
		if (s1)
			free(s1);
	}
	else if (flag == 2)
	{
		if (s2)
			free(s1);
	}
	else if (flag == 3)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s1);
	}
	return ;
}
