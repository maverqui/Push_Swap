

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	temp = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
	{
		temp = n + 48;
		write(fd, &temp, 1);
	}
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	// size_t n et size_t i change en int n, i
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	b_strategy(char *str)
{
	char	adapt[] = "--adaptive";
	char	simp[] = "--simple";
	char	med[] = "--medium";
	char	complex[] = "--complex";

	//possibilite de faire if(ft_strncmp(str, adapt, sizeof(adapt) - 1) == 0)
	if(ft_strncmp(str, adapt, 10) == 0)
		write(2, "Adaptive / O(n√n)", 17);
	if(ft_strncmp(str, simp, 8) == 0)
		write(2, "Simple / O(n2)", 14);
	if(ft_strncmp(str, med, 8) == 0)
		write(2, "Medium / O(n√n)", 15);
	if(ft_strncmp(str, complex, 10) == 0)
		write(2, "Complex / O(n log n)", 20);

// --simple 	O(n2) 
// --medium 	O(n√n) 
// --complex 	O(n log n) 

	write(2, "\n", 1);
}





void	benchmark(t_operations *operations, /*int bench_flag, char *strat_flag, float disorder*/)
{
int total;

total = operations->sa + operations->sb + operations->ss + operations->pa
+ operations->pb + operations->ra + operations->rb + operations->rr +
operations->rra + operations->rrb + operations->rrr;


write(2, "[bench] disorder:	", 18);
//use fonction to print float
write(2, "%\n", 2);
write(2, "[bench] strategy:	", 18);
b_strategy(strat_flag);
write(2, "[bench] total_ops:	", 19);
ft_putnbr_fd(total, 2);
write(2, "\n", 1);
write(2, "[bench]	sa:	", 12);
ft_putnbr_fd(operations->sa, 2);
write(2, "[bench]	sb:	", 12);
ft_putnbr_fd(operations->sb, 2);
write(2, "[bench]	ss:	", 12);
ft_putnbr_fd(operations->ss, 2);
write(2, "[bench]	pa:	", 12);
ft_putnbr_fd(operations->pa, 2);
write(2, "[bench]	pb:	", 12);
ft_putnbr_fd(operations->pb, 2);
write(2, "\n", 1);
write(2, "[bench]	ra:	", 12);
ft_putnbr_fd(operations->ra, 2);
write(2, "[bench]	rb:	", 12);
ft_putnbr_fd(operations->rb, 2);
write(2, "[bench]	rr:	", 12);
ft_putnbr_fd(operations->rr, 2);
write(2, "[bench]	rra:	", 13);
ft_putnbr_fd(operations->rra, 2);
write(2, "[bench]	rrb:	", 13);
ft_putnbr_fd(operations->rrb, 2);
write(2, "[bench]	rrr:	", 13);
ft_putnbr_fd(operations->rrr, 2);
write(2, "\n", 1);
}


// %.2f = float avec 2 chiffres apres la virgule
// ft_printf("[bench] disorder: %.2f%%\n", );
// ft_printf("[bench] strategy:	%s\n", );
// ft_printf("[bench] total_ops:	%d\n", total);
// ft_printf("[bench]	sa:	%d	sb:	%d", operations->sa, operations->sb);
// ft_printf("	ss:	%d	pa:	%d", operations->ss, operations->pa);
// ft_printf("	pb:	%d\n", operations->pb);
// ft_printf("[bench]	ra:	%d	rb:	%d", operations->ra, operations->rb);
// ft_printf("	rr:	%d	rra:	%d", operations->rr, operations->rra);
// ft_printf("	rrb:	%d	rrr:	%d\n", operations->rrb, operations->rrr);


