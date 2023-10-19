/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:04:17 by telufulu          #+#    #+#             */
/*   Updated: 2023/10/19 17:51:56 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, char *msg)
{
	size_t	i;
	int		j;

	i = 0;
	while (msg && msg[i])
	{
		j = 128;
		while (j)
		{
			if ((msg[i] & j) == j)
			{
				kill(pid, SIGUSR1);
				usleep(150);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(150);
			}
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
		msg = ft_strdup(argv[argc - 1]);
		if (!msg)
			return (-1);
		pid = (pid_t)ft_atoi(argv[argc -2]);
		send_msg(pid, msg);
		free(msg);
	}
	return (0);
}
