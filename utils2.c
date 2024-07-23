/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:36:58 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/23 19:26:04 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_memset(void *ptr, int len)
{
	char	*ptr_char;
	int		i;

	ptr_char = (char *)ptr;
	i = 0;
	while (i < len)
	{
		ptr_char[i] = 0;
		i++;
	}
}

int	get_len_int(long long numb)
{
	int	len;

	len = 0;
	while (numb)
	{
		numb /= 10;
		len++;
	}
	if (len == 0)
		len = 1;
	return (len);
}

void	fill_arr_int(char *out, long long *numb, int i, int size)
{
	if (i < size)
	{
		fill_arr_int(out + 1, numb, i + 1, size);
		*out = (*numb % 10 + '0');
		*numb /= 10;
	}
}

char	*itos(long long numb)
{
	int		i;
	char	*out;

	i = get_len_int(numb);
	out = malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	if (numb == 0)
		out[0] = '0';
	else
	{
		fill_arr_int(out, &numb, 0, i);
	}
	out[i] = 0;
	return (out);
}

int	is_dir(char *path)
{
	struct stat	file_stat;

	if (lstat(path, &file_stat) != 0)
		return (-1);
	return (S_ISDIR(file_stat.st_mode));
}