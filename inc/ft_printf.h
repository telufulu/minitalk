/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:47:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/28 18:36:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define NB_OF_CONV 9

typedef struct s_store
{
	char	conv;
	size_t	(*funct)(va_list);
}				t_store;

// ft_printf.c
int		ft_printf(char const *s, ...);

// conv_funct_char.c
size_t	conv_per(va_list arg);
size_t	conv_char(va_list arg);
size_t	conv_string(va_list arg);
size_t	conv_addrss(va_list arg);

// conv_funct_num.c
size_t	conv_dec(va_list arg);
size_t	conv_unsig(va_list arg);
size_t	conv_hex(va_list arg);
size_t	conv_uphex(va_list arg);

// libft_utils.c
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_putnbr_base(int nb, char *base);
size_t	ft_putptr(unsigned long long nb, char *base);
size_t	ft_putunsig(unsigned int nb);
#endif
