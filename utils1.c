/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:57:41 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/23 15:46:19 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	str_compare_sort(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str1[i] == str2[i] && str1[i] == 0)
			break ;
		else if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
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

int	str_time_sort(char *str1, char *str2)
{
	long long	f1;
	long long	f2;

	f1 = get_time_created(str1);
	f2 = get_time_created(str2);
	if (f1 == f2)
		return (!str_compare_sort(str1, str2));
	return (f1 > f2);
}

void	sort_strings(char **arr, int (*func)(char *str1, char *str2))
{
	int		len;
	int		i;
	int		e;
	char	*temp;

	len = len2d_array(arr);
	i = 0;
	while (i < len)
	{
		e = 0;
		while (e < len - 1)
		{
			if (func(arr[e], arr[e + 1]))
			{
				temp = arr[e];
				arr[e] = arr[e + 1];
				arr[e + 1] = temp;
			}
			e++;
		}
		i++;
	}
}

void	reverse_strings(char **arr)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = len2d_array(arr);
	len--;
	while (i < len)
	{
		temp = arr[len];
		arr[len] = arr[i];
		arr[i] = temp;
		i++;
		len--;
	}
}
