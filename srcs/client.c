/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:17 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/20 17:52:10 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_msg(pid_t pid, char *msg)
{
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	len = ft_strlen(msg);
	while (msg && i <= len)
	{
		j = 128;
		while (j)
		{
			if ((msg[i] & j) == j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j = j >> 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		msg = argv[argc - 1];
		pid = (pid_t)ft_atoi(argv[argc -2]);
		send_msg(pid, msg);
	}
	return (0);
}
