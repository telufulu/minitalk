/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:42:41 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/15 19:16:16 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	ft_bzero(aux, len);
	return (aux);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (*s1 != '\0')
		res[i++] = (char)*s1++;
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res * neg);
}
