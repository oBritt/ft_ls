/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:36 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/22 16:13:19 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	add_flag_to_data(t_data *data, char c)
{
	if (c == 'R')
		data->option_cr = 1;
	else if (c == 'a')
		data->option_a = 1;
	else if (c == 'g')
		data->option_g = 1;
	else if (c == 'r')
		data->option_r = 1;
	else if (c == 't')
		data->option_t = 1;
	else if (c == 'l')
		data->option_l = 1;
	else
		return (1);
	return (0);
}

int	check_if_flag(char *t)
{
	int			i;

	i = 0;
	if (str_len(t) > 1 && t[0] == '-')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	validate_flag(t_data *data, char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (add_flag_to_data(data, s[i]))
			return (1);
		i++;
	}
	return (0);
}
