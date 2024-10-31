/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:27:12 by gamoraes          #+#    #+#             */
/*   Updated: 2023/11/13 01:30:36 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *string, char character)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (string[i])
	{
		while (string[i] == character)
			i++;
		if (string[i])
		{
			while (string[i] != character && string[i])
				i++;
			words++;
		}
	}
	return (words);
}

static void	ft_free_split(char **wordslst)
{
	size_t	i;

	i = 0;
	while (wordslst[i])
		free(wordslst[i++]);
	free(wordslst);
}

static char	**ft_fill_split(const char *s, char c, char **wordslst)
{
	size_t	i;
	size_t	delimiters;
	size_t	words;

	i = 0;
	delimiters = 0;
	while (s[i])
	{
		words = 0;
		if ((s[i] != c) && (i + words < ft_strlen(s)))
		{
			while ((s[i + words] != c) && (i + words < ft_strlen(s)))
				words++;
			wordslst[delimiters] = ft_substr(s, i, words);
			if (!wordslst[delimiters])
			{
				ft_free_split(wordslst);
				return (NULL);
			}
			i += words - 1;
			delimiters++;
		}
		i++;
	}
	return (wordslst);
}

char	**ft_split(char const *string, char character)
{
	char	**wordslst;
	size_t	words;

	if (!string)
		return (NULL);
	words = ft_count_words(string, character);
	wordslst = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!wordslst)
		return (NULL);
	return (ft_fill_split(string, character, wordslst));
}
