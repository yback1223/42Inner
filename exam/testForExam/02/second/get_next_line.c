int get_next_line(int fd)
{
	char	*line = malloc(1000), *word = line;
	while (read(fd, word, 1) > 0 && *word++ != '\n')
	return (word > line) ? (*word = 0, line) : (free(line), NULL);
}
