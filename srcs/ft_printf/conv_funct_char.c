/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_funct_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:33:51 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/28 18:37:40 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_per(va_list arg)
{
	arg = 0;
	return (write(1, "%", 1));
}

size_t	conv_char(va_list arg)
{
	int		c;
	size_t	i;

	c = va_arg(arg, int);
	i = write(1, &c, 1);
	return (i);
}

size_t	conv_string(va_list arg)
{
	char	*s;
	size_t	i;

	i = 0;
	s = va_arg(arg, char *);
	if (s)
		i = write(1, s, ft_strlen(s));
	else if (!s)
		i = write(1, "(null)", 6);
	return (i);
}

size_t	conv_addrss(va_list arg)
{
	size_t				i;
	size_t				x;
	unsigned long int	p;

	i = 0;
	p = va_arg(arg, unsigned long long);
	i = write(1, "0x", 2);
	if (i < 0)
		return (i);
	x = ft_putptr(p, "0123456789abcdef");
	if (x < 0)
		return (x);
	return (i + x);
}
