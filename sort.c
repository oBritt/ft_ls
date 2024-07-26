/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:47:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/25 12:32:41 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_by_size(char *str1, char *str2)
{
	long long	size1;
	long long	size2;

	size1 = get_size_numb(str1);
	size2 = get_size_numb(str2);
	if (size1 == -1 || size2 == -1)
	{
		return (-1);
	}
	if (size1 == size2)
		str_compare_sort(str1, str2);
	return (size2 > size1);
}

int	sort_files(t_data *data, char **files)
{
	if (data->option_f)
	{
	}
	else if (data->option_cs)
	{
		if (sort_strings(files, &sort_by_size))
			return (1);
	}
	else if (data->option_t)
	{
		if (sort_strings(files, &str_time_sort))
			return (1);
	}
	else
	{
		if (sort_strings(files, &str_compare_sort))
			return (1);
	}
	if (data->option_r && !data->option_f)
		reverse_strings(files);
	return (0);
}
