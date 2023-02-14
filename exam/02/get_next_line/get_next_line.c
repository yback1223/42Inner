#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*line;
	char	*word;

	line = malloc(1000);
	word = line;
	while (read(fd, word, 1) > 0 && *word++ != '\n')
		;
	if (word > line)
	{
		//printf("word = %s\nline = %s\n", word, line);
		*word = 0;
		return (line);
	}
	else
	{
		free(line);
		line = NULL;
		return (NULL);
	}
}

int main(void)
{
    char	*line;
 
	line = get_next_line(0);
    while(line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(0);
    }
    return 0;
}
