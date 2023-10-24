/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:17 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/24 17:09:45 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	send_msg(pid_t pid, char *msg)
{
	size_t	i;
	int		j;
	size_t	len;
	int		check;

	i = 0;
	check = 0;
	len = ft_strlen(msg);
	while (msg && i <= len)
	{
		j = 128;
		while (j)
		{
			if ((msg[i] & j) == j)
				check = kill(pid, SIGUSR1);
			else
				check = kill(pid, SIGUSR2);
			if (check < 0)
				ft_error(1);
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
		if (pid < 0 || ft_isnotdigit(argv[argc - 2]))
			ft_error(1);
		send_msg(pid, msg);
	}
	else
		ft_error(2);
	return (0);
}
