/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:33 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/19 17:52:12 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static char	res;
	static int	i;

	if (signal == SIGUSR1)
		res |= 1;
	res = res << 1;
	i++;
	if (i == 7)
	{
		ft_printf("%c", res);
		i = 0;
		res = 0;
	}
}

int	main()
{
	ft_printf("pid: %i\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();	
	return (0);
}
