#include "libft/libft.a"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = c;
	while (i > 0)
	{
		i--;
		temp_char = c >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Invalid number of arguments\n");
		sleep(1);
		printf("Please try again using this format:\n[./client <SERVER ID (PID)> <MESSAGE>\n");
		exit(EXIT_FAILURE);
	}
	else
		send_signal(ft_atoi(av[1]), av[2]);
	return (0);
}
