/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:24 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:05:42 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int n);
static int	ft_tatoi(const char *nptr, int sign);

int	ft_atoi(const char *nptr)
{
	int	sign;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' && nptr[1] >= '0' && nptr[1] <= '9')
		nptr++;
	else if (*nptr == '-' && nptr[1] >= '0' && nptr[1] <= '9')
	{
		nptr++;
		sign = -1;
	}
	if (*nptr >= '0' && *nptr <= '9')
		return (ft_tatoi(nptr, sign));
	return (0);
}

static int	ft_tatoi(const char *nptr, int sign)
{
	int	len;
	int	i;
	int	max;
	int	numb;

	i = -1;
	len = 0;
	max = 0;
	numb = 0;
	while (nptr[len] >= '0' && nptr[len] <= '9')
		len++;
	max = len;
	while (++i < max)
		numb = numb + (nptr[i] - 48) * ft_pow(--len);
	return (numb * sign);
}

static int	ft_pow(int n)
{
	int	base;
	int	i;

	i = -1;
	base = 1;
	while (++i < n)
		base = base * 10;
	return (base);
}
