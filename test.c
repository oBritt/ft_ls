// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <time.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <pwd.h>
// #include <grp.h>
// #include <stdio.h>
// #include <dirent.h>

// int	str_len(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_str_dup(char *s)
// {
// 	char	*out;
// 	int		i;

// 	out = malloc((str_len(s) + 1) * sizeof(char));
// 	if (!out)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		out[i] = s[i];
// 		i++;
// 	}
// 	return (out);
// }



// int main(int argc, char *argv[]) {

// 	char **out = get_files("./");
// 	for (int i = 0; out[i]; i++)
// 	{
// 		printf("%s\n", out[i]);
// 	}
//     return 0;
// }