/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:10:13 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:37:59 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_nbr(long long n)
{
	char	temp;

	if (n)
	{
		temp = n % 10 + '0';
		print_nbr(n / 10);
		write(1, &temp, 1);
	}
}

void	ft_put_nbr(long long n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_nbr(n);
}

void	super_freeing(char ***allocated)
{
	int	i;
	int	e;

	i = 0;
	while (allocated[i])
	{
		e = 0;
		while (allocated[i][e])
		{
			free(allocated[i][e]);
			e++;
		}
		free(allocated[i]);
		i++;
	}
	free(allocated);
}

char	*fill_spaces(char *str, int len)
{
	int		leng;
	char	*output;
	int		i;
	int		ptr;

	leng = str_len(str);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i < len - leng)
	{
		output[i] = ' ';
		i++;
	}
	ptr = 0;
	while (str[ptr])
		output[i++] = str[ptr++];
	output[i] = 0;
	return (output);
}
