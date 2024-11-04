/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:12 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 17:05:30 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** Part 1 Functions
*/

int					ft_atoi(const char *nptr);
void				ft_bzero(void *string, size_t length);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dest, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t length);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *string, int character, size_t length);
size_t				ft_strlcat(char *dest, const char *src, size_t length);
void				*ft_memchr(const void *string, int character,
						size_t length);
size_t				ft_strlcpy(char *dest, const char *src, size_t length);
char				*ft_strdup(char *s1, int flag);
size_t				ft_strlen(const char *string);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t length);
char				*ft_strrchr(const char *string, int character);
char				*ft_strchr(const char *string, int character);
int					ft_strncmp(const char *s1, const char *s2, size_t length);
int					ft_tolower(int character);
int					ft_toupper(int character);

/*
** Part 2 Functions
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int flag);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *string, char character);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *string, char (*f)(unsigned int,
							char));
void				ft_striteri(char *string, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char character, int fd);
void				ft_putstr_fd(char *string, int fd);
void				ft_putendl_fd(char *string, int fd);
void				ft_putnbr_fd(int number, int fd);

/*
** New Functions
*/

int					ft_isspace(int c);
int					ft_ismeta(char *c);

/*
** Bonus Functions
*/

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
