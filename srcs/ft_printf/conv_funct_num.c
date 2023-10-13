/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:42:16 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/28 17:48:16 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_dec(va_list arg)
{
	size_t	i;
	int		d;

	d = va_arg(arg, int);
	i = ft_putnbr_base(d, "0123456789");
	return (i);
}

size_t	conv_unsig(va_list arg)
{
	size_t	i;
	int		d;

	d = va_arg(arg, unsigned int);
	i = ft_putunsig(d);
	return (i);
}

size_t	conv_hex(va_list arg)
{
	size_t	i;
	int		d;

	d = va_arg(arg, int);
	i = ft_putnbr_base(d, "0123456789abcdef");
	return (i);
}

size_t	conv_uphex(va_list arg)
{
	size_t	i;
	int		d;

	d = va_arg(arg, int);
	i = ft_putnbr_base(d, "0123456789ABCDEF");
	return (i);
}
