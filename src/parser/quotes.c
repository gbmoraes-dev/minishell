#include "../../include/minishell.h"

int	find_next_quote(char *line)
{
	char	quote;
	int		quote_distance;

	if (!line || !(*line))
		return (0);
	quote = *line;
	line++;
	quote_distance = 1;
	while (*line != quote)
	{
		if (!(*line))
			return (-1);
		quote_distance++;
		line++;
	}
	return (quote_distance);
}

int	validate_quotes(char *line)
{
	int	quote_distance;

	if (!line)
		return (1);
	quote_distance = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			quote_distance = find_next_quote(line);
			if (quote_distance == -1)
				return (1);
			line += quote_distance + 1;
		}
		else
			line++;
	}
	return (0);
}

static void	set_start_and_end_quotes_to_null(char *line);

char	*remove_quotes(char *line, int should_free)
{
	char	*new_line;
	int		i;
	int		line_len;

	if (!line)
		return (NULL);
	new_line = NULL;
	i = 0;
	line_len = ft_strlen(line);
	if (!ft_strchr(line, '\'') || !ft_strchr(line, '\"'))
		return (line);
	set_start_and_end_quotes_to_null(line);
	while (!line[i] && i < line_len)
		i++;
	while (i < line_len)
	{
		new_line = ft_strjoin(new_line, &line[i]);
		i += ft_strlen(&line[i]) + 1;
		while (!line[i] && i < line_len)
			i++;
	}
	if (should_free)
		free(line);
	return (new_line);
}

static void	set_start_and_end_quotes_to_null(char *line)
{
	int	next_quote;

	if (!line)
		return ;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			next_quote = find_next_quote(line);
			*line = '\0';
			line += next_quote;
			*line = '\0';
			line++;
		}
		else
			line++;
	}
	return ;
}
