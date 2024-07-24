/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:01:18 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:20:29 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_len_ar(char **arr)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (arr[i])
	{
		sum += str_len(arr[i]);
		i++;
	}
	return (sum);
}

char	*join_2d_array(char **arr)
{
	int		len;
	int		i;
	char	*out;
	int		e;
	int		ptr;

	len = get_len_ar(arr);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	ptr = 0;
	while (arr[i])
	{
		e = 0;
		while (arr[i][e])
			out[ptr++] = arr[i][e++];
		i++;
	}
	out[ptr] = 0;
	return (out);
}