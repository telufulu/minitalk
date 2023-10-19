/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:48:56 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/28 15:53:16 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_store(t_store *store)
{
	store[0] = (t_store){'c', &conv_char};
	store[1] = (t_store){'s', &conv_string};
	store[2] = (t_store){'p', &conv_addrss};
	store[3] = (t_store){'d', &conv_dec};
	store[4] = (t_store){'i', &conv_dec};
	store[5] = (t_store){'u', &conv_unsig};
	store[6] = (t_store){'x', &conv_hex};
	store[7] = (t_store){'X', &conv_heX};
}

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	size_t	nb_chars;
	t_store	store[NB_OF_CONV + 1];
	int		i;

	nb_chars = 0;
	va_start(arg, s);
	ft_bzero(store, NB_OF_CONV);
	init_store(store);
	while (s && *s)
	{
		if (*s == '%')
		{
			i = 0;
			s++;
			if (*s == '%')
				nb_chars += write(1, "%", 1);
			if (nb_chars < 0)
				return (nb_chars);
			while (i < NB_OF_CONV && store[i].conv != *s)
				i++;
			if (i < NB_OF_CONV)
				nb_chars += store[i].funct(arg);
			if (i > NB_OF_CONV)
				nb_chars += write(1, s, 1);
			s++;
		}
		else
			nb_chars += write(1, s++, 1);
		if (nb_chars < 0)
			return (nb_chars);
	}
	va_end(arg);	
	return (nb_chars);
}
