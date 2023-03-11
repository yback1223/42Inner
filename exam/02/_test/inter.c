int is_already_in_answer(char *answer, char word)
{
	int i;

	i = 0;
	while (answer[i])
		if (answer[i] == word)
			return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	answer[255];

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	k = 0;
	while (av[1][++i])
	{
		j -= 1;
		while (av[2][++j])
			if (av[1][i] == av[2][j] && is_already_in_answer(answer, av[1][i]))
				answer[k++] = av[1][i];
	}
	write(1, answer, ft_strlen(answer));
	return (0);
}
 
