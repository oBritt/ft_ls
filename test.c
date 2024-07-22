#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_str_dup_len(char *str, int len)
{
	char	*output;
	int		i;

	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

char	*get_time_stamp(char *str, char *path)
{
	char	*output;
	int		len;

	len = str_len(path);
	output = ft_str_dup_len(str + 4, 12);
	return (output);
}

int main(int argc, char *argv[]) {
    struct stat fileStat;
    
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    // Get file status
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }
    
    // Get the modification time
    time_t modTime = fileStat.st_mtime;
    
    // Convert it to a human-readable string
    char *timeStr = ctime(&modTime);
    if (timeStr == NULL) {
        printf("Error converting time.\n");
        return 1;
    }
    
    // Print the modification time
    printf("File: %s\n", argv[1]);
    printf("Last modification time: %s", get_time_stamp(timeStr, argv[1]));
    
    return 0;
}