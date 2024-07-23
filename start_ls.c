/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:55:20 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/23 15:43:01 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	handle_arguments(t_data *data, char *str)
{
	long long	blocks;
	char		**files;

	files = get_files(data, str, &blocks);
	if (!files)
		return (1);
	if (improve_files(&files, str))
		return (freeing(files, -1), 1);
	if (data->option_t)
		sort_strings(files, &str_time_sort);
	else
		sort_strings(files, &str_compare_sort);
	if (data->option_t)
		reverse_strings(files);
    for (int i = 0; files[i]; i++)
        printf("%s %lli\n", files[i], get_time_created(files[i]));
    return (0);
}

int	start_ls(t_data *data)
{
    if (!data->files)
    {
        handle_arguments(data, "./");
    }
    else
    {
        printf("asd");
    }
    return (1);
}