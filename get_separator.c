/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:55:46 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:53 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_separator(t_data *data, char *sep)
{
	if (data->option_l || data->option_1)
	{
		sep[0] = '\n';
		sep[1] = 0;
	}
	else if (data->option_m)
	{
		sep[0] = ',';
		sep[1] = ' ';
		sep[2] = 0;
	}
	else
	{
		sep[0] = ' ';
		sep[1] = 0;
	}
}
