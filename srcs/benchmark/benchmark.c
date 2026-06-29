#include "../../push_swap.h"

static	void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putfloat_fd(float n, int fd)
{
	int	entier;
	int	decimal;

	entier = n; // float to int
	decimal = (n - entier) * 100 + 0.5; //apres virgule -> entier
	if (n == 100.00)
		write(fd, "100.00", 6);
	else
	{
		entier =  (n / 10) + '0';
		write(fd, &entier, 1);
		entier = n;
		entier =  (entier % 10) + '0';
		write(fd, &entier, 1);
		write(fd, ".", 1);
		entier =  (decimal / 10) + '0';
		write(fd, &entier, 1);
		decimal =  (decimal % 10) + '0';
		write(fd, &decimal, 1);
	}
}
