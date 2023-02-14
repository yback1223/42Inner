#include "get_next_line2.h"


char *get_next_line(int fd)
{
    char *line = malloc(10000), *word = line;
    while(read(fd, word, 1) > 0 && *word++ != '\n' )
		printf("word = %s\n", word);
    return ((word > line) ? (*word = 0, line) : (free(line), NULL));
}

int main(void)
{
    char *line;

    line = get_next_line(0);
    while(line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(0);
    }
    return 0;
}
