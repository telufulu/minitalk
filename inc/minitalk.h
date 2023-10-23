/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:05:32 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/23 20:34:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

//utils.c
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_putnbr_base(int nb, char *base);
void	ft_error(int err);
#endif
