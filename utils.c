
#include "ft_ls.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	len2d_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_join(char *s1, char *s2)
{
	char	*out;
	int		ptr1;
	int		ptr2;

	out = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ptr1 = 0;
	ptr2 = 0;
	while (s1[ptr1])
	{
		out[ptr2++] = s1[ptr1++];
	}
	ptr1 = 0;
	while (s2[ptr1])
	{
		out[ptr2++] = s2[ptr1++];
	}
	out[ptr2] = 0;
	return (out);
}

char	*ft_str_dup(char *s)
{
	char	*out;
	int		i;

	out = malloc((str_len(s) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	return (out);
}

void	freeing(char **arr, int len)
{
	int	i;

	i = 0;
	if (len == -1)
		len = 2e9;
	while (arr[i] && i < len)
	{
		free(arr[i]);
		i++;
	}
}