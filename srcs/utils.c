/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:42:41 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/23 20:34:38 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(int err)
{
	write(1, "\x1b[31merror: \x1b[0m", 16);
	if (err == 1)
		write(1, "sigaction failure\n", 18);
	else if (err == 2)
		write(1, "argument pid is wrong\n", 22);
	else if (err == 3)
		write(1, "wrong number of arguments\n", 26);
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
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

size_t	ft_putnbr_base(int nb, char *base)
{
	unsigned int	nbr;
	unsigned int	bs;
	size_t			nb_chars;
	int				aux;

	nb_chars = 0;
	nbr = 0;
	bs = ft_strlen(base);
	if (nb < 0 && bs == 10)
	{
		nb_chars += write(1, "-", 1);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr > bs - 1)
		nb_chars += ft_putnbr_base((nbr / bs), base);
	aux = (nbr % bs);
	nb_chars += write(1, &base[aux], 1);
	return (nb_chars);
}
