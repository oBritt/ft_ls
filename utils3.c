/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:39:43 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 11:24:22 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_last_app(char *str, char c)
{
	int	last;
	int	i;

	i = 0;
	last = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	return (last);
}

int	get_prev_last_app(char *str, char c)
{
	int	last;
	int	i;
	int	prev;

	i = 0;
	last = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			prev = last;
			last = i;
		}
		i++;
	}
	return (prev);
}

int	same_strings(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str1[i] != str2[i])
			return (0);
		if (!str1[i])
			break ;
		i++;
	}
	return (1);
}

void	swap_pointers(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
