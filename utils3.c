/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:39:43 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/23 19:49:16 by obrittne         ###   ########.fr       */
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