#include <unistd.h>

void	ft_putfloat_fd(float n)
{
	int	entier;
	int	decimal;

	entier = n;
	decimal = (n - entier) * 100 + 0.5;
	if (n == 100.00)
		write(1, "100.00", 6);
	else
	{
		entier =  (n / 10) + '0';
		write(1, &entier, 1);
		entier = n;
		entier =  (entier % 10) + '0';
		write(1, &entier, 1);
		write(1, ".", 1);
		//"entier" devient un simple temp, pour eviter de recreer une variable
		entier =  (decimal / 10) + '0';
		write(1, &entier, 1);
		decimal =  (decimal % 10) + '0';
		write(1, &decimal, 1);
	}
}

int main()
{
ft_putfloat_fd(8.00);

}