/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_files4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:14:24 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 13:57:14 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_char(int t)
{
	if (t == 1)
		return ('K');
	else if (t == 2)
		return ('M');
	else if (t == 3)
		return ('G');
	else
		return ('T');
}

static void	handle_3(char *output, long long numb, int c)
{
	output[0] = ' ';
	output[1] = numb / 100;
	output[2] = numb / 10 % 10;
	output[3] = get_char(c);
	output[4] = 0;
}

static void	handle_4(char *output, long long numb, int c)
{
	output[0] = numb / 1000;
	output[1] = numb / 100 % 10 ;
	output[2] = numb / 10 % 10;
	output[3] = get_char(c);
	output[4] = 0;
}

static char	*handle_size_h(long long numb)
{
	char	output[5];
	int		counter;

	numb *= 10;
	counter = 0;
	while (numb >= 10000)
	{
		numb /= 1000;
		counter++;
	}
	if (numb < 100)
	{
		output[0] = numb / 10;
		output[1] = '.';
		output[2] = numb % 10;
		output[3] = get_char(counter);
		output[4] = 0;
	}
	else if (numb < 1000)
		handle_3(output, numb, counter);
	else
		handle_4(output, numb, counter);
	return (ft_str_dup(output));
}

char	*get_size_h(char *path)
{
	long long	numb;
	char		*t;
	char		*other;

	numb = get_size_numb(path);
	if (numb == -1)
		return (NULL);
	if (numb < 1000)
	{
		t = itos(numb);
		if (!t)
			return (NULL);
		other = str_join(t, "B");
		free(t);
		return (other);
	}
	else
	{
		return (handle_size_h(numb));
	}
}