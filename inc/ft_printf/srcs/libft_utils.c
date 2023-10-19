/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:29:35 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/28 02:28:01 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*x;

	x = s;
	while (n--)
		*x++ = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

size_t	ft_putptr(unsigned long long nb, char *base)
{
	unsigned long long	bs;
	size_t				nb_chars;
	int					aux;

	nb_chars = 0;
	bs = ft_strlen(base);
	if (nb > 15)
		nb_chars += ft_putptr((nb / bs), base);
	aux = (nb % bs);
	nb_chars += write(1, &base[aux], 1);
	return (nb_chars);
}

size_t	ft_putunsig(unsigned int nb)
{
	char	*base;
	size_t	nb_chars;
	int		aux;

	nb_chars = 0;
	base = "0123456789";
	if (nb > 9)
		nb_chars += ft_putunsig(nb / 10);
	aux = (nb % 10);
	nb_chars += write(1, &base[aux], 1);
	return (nb_chars);
}
