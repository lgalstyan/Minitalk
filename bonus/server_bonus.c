/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:01:57 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/12 15:02:03 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i = (i * -1);
		write(1, "-", 1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
	}
	else
		ft_putchar(i + '0');
}

void	receve_sig(int sig)
{
	static unsigned char	si = 0;
	static int				cnt = 0;

	++cnt;
	si = si << 1;
	if (sig == SIGUSR1)
		si = si | 1;
	if (cnt == 8)
	{
		write(1, &si, 1);
		cnt = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &receve_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID :  ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
