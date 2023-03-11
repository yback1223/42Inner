#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_already_in_answer(char *answer, char word)
{
	int	i;

	i = -1;
	while (answer[++i])
		if (answer[i] == word)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		av_1_index;
	int		av_2_index;
	int		answer_index;
	char	answer[255];

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	av_1_index = -1;
	answer_index = 0;
	while (av[1][++av_1_index])
	{
		av_2_index = -1;
		while (av[2][++av_2_index])
			if (av[1][av_1_index] == av[2][av_2_index] && is_already_in_answer(answer, av[1][av_1_index]) == 0)
				answer[answer_index++] = av[1][av_1_index];
	}
	write(1, answer, ft_strlen(answer));
	return (0);
}
