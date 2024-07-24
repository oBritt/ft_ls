/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:36 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 13:07:07 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// l => basic
// r => reversed
// t => sorted by time
// R => recursively opens all of the dirs
// a => shows also files which starts with dot

// A => shows everything except . and ..
// g => l but no owner
// 1 => each is in separate line
// i =>  serial number
// n => makes group and user numbers -l
// S => sorts by size
// s => display how many blocks 
// h => display in kBytes etc
// f => not sorted turns on -a

int	add_flag_to_data1(t_data *data, char c)
{
	if (c == 'h')
		data->option_h = 1;
	else if (c == '1')
		data->option_1 = 1;
	else if (c == 'S')
		data->option_cs = 1;
	else if (c == 's')
		data->option_s = 1;
	else if (c == 'i')
		data->option_i = 1;
	else if (c == 'n')
		data->option_n = 1;
	else
		return (1);
	return (0);
}

int	add_flag_to_data(t_data *data, char c)
{
	if (c == 'R')
		data->option_cr = 1;
	else if (c == 'a')
		data->option_a = 1;
	else if (c == 'g')
	{
		data->option_l = 1;
		data->option_g = 1;
	}
	else if (c == 'r')
		data->option_r = 1;
	else if (c == 't')
		data->option_t = 1;
	else if (c == 'l')
		data->option_l = 1;
	else if (c == 'A')
		data->option_ca = 1;
	else if (c == 'f')
	{
		data->option_f = 1;
		data->option_a = 1;
	}
	else
		return (add_flag_to_data1(data, c));
	return (0);
}

int	check_if_flag(char *t)
{
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
