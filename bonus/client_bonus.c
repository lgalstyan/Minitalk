/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:01:41 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/12 15:03:06 by lgalstya         ###   ########.fr       */
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

int	send_sig(char *str, int pid)
{
	int	i;
	int	bit;
	int	flag;

	flag = -1;
	i = 0;
	while (str[i])
	{
		bit = 128;
		while (bit != 0)
		{
			if (str[i] & bit)
				flag = kill(pid, SIGUSR1);
			else
				flag = kill(pid, SIGUSR2);
			usleep(100);
			bit = bit >> 1;
		}
		i++;
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	int	flag;

	flag = -1;
	if (argc == 3)
	{
		flag = send_sig(argv[2], ft_atoi(argv[1]));
		if (flag >= 0)
			write(1, "The message has successfully reached the server\n", 49);
	}
	return (0);
}
