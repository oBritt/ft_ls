/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:55:20 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 16:18:29 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	output_addition(char **addition, int i)
{
	int	len;

	len = str_len(addition[i]);
	write(1, addition[i], len);
	if (len)
		write(1, " ", 1);
	free(addition[i]);
}

int	output_files(t_data *data, char **files)
{
	int		i;
	char	sep[10];
	int		ind;
	int		len;
	char	**addition;

	addition = option_addition(data, files);
	if (!addition)
		return (1);
	i = 0;
	get_separator(data, sep);
	len = len2d_array(files);
	if (len != 0)
	{
		while (files[i])
		{
			output_addition(addition, i);
			ind = get_last_app(files[i], '/');
			write(1, &files[i][ind + 1], str_len(files[i]) - ind - 1);
			if (i != len - 1)
				write(1, &sep, str_len(sep));
			i++;
		}
		write(1, "\n", 1);
	}
	return (free(addition), 0);
}

int	handle_arguments(t_data *data, char *str)
{
	long long	blocks;
	char		**files;

	files = get_files(data, str, &blocks);
	if (!files)
		return (1);
	if (improve_files(&files, str))
		return (freeing(files, -1), 1);
	if (sort_files(data, files))
		return (freeing(files, -1), 1);
	print_total();
	if (output_files(data, files))
		return (freeing(files, -1), 1);
	if (data->option_cr)
		if (handle_option_cr(data, files))
			return (freeing(files, -1), 1);
	freeing(files, -1);
	return (0);
}

int	start_ls(t_data *data)
{
	char	**files;
	char	**dirs;

	if (!data->files)
	{
		if (handle_arguments(data, "./"))
			return (1);
	}
	else
	{
		files = get_files_dirs(data->files, 0);
		dirs = get_files_dirs(data->files, 1);
		(void)files;
		(void)dirs;
	}
	return (0);
}