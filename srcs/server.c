/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:33 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/23 20:36:09 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t *info, void *context)
{
	static char	res;
	static int	x;
	int			check;

	context = 0;
	if (!x)
		x = 128;
	if (signal == SIGUSR1)
		res |= x;
	x = x >> 1;
	if (!x)
	{
		if (!res)
		{
			check = write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			check = write(1, &res, 1);
		x = 128;
		res = 0;
		if (check < 0)
			exit(-1);
	}
}

static void	set_sig(void)
{
	struct sigaction sig;

	if (sigemptyset(&sig.sa_mask))
		ft_error(1);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
}

int	main(void)
{
	set_sig();
	write(1, "pid: ", 5);
	ft_putnbr_base(getpid(), "0123456789");
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
