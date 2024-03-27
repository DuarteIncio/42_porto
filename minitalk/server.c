#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handler(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main()
{
	printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}
