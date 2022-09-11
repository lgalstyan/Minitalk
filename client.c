/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:49:16 by lgalstya          #+#    #+#             */
/*   Updated: 2022/07/09 15:01:39 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	c;
	int	min;
	int	n;

	c = 0;
	min = 1;
	n = 0;
	if (!str)
		return (0);
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '-')
		min = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		n = (str[c] - '0') + (n * 10);
		c++;
	}
	return (n * min);
}

void	send_sig(char *str, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 128;
		while (bit != 0)
		{
			if (str[i] & bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit = bit >> 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_sig(argv[2], ft_atoi(argv[1]));
	return (0);
}
