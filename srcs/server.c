/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:33 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/23 21:10:58 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal)
{
	static char	res;
	static int	x;
	int			check;

	if (!x)
		x = 128;
	if (signal == SIGUSR1)
		res |= x;
	x = x >> 1;
	if (!x)
	{
		if (!res)
			check = write(1, "\n", 1);
		else
			check = write(1, &res, 1);
		x = 128;
		res = 0;
		if (check < 0)
			exit(-1);
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	write(1, "pid: ", 5);
	ft_putnbr_base(getpid(), "0123456789");
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
