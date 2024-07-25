/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:55:20 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/25 12:30:50 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	output_files(t_data *data, char **files)
{
	int		i;
	char	sep[10];
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
			output_file(files, i, len, sep);
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

	blocks = 0;
	files = get_files(data, str, &blocks);
	if (!files)
		return (1);
	if (improve_files(&files, str))
		return (freeing(files, -1), 1);
	if (sort_files(data, files))
		return (freeing(files, -1), 1);
	if (files[0] != NULL)
		print_total(data, blocks);
	if (output_files(data, files))
		return (freeing(files, -1), 1);
	if (data->option_cr)
		if (handle_option_cr(data, files))
			return (freeing(files, -1), 1);
	freeing(files, -1);
	return (0);
}

int	handle_dirs(t_data *data, char **dirs, int files)
{
	int	i;

	i = 0;
	while (dirs[i])
	{
		if (!(dirs[1] == NULL && files == 0))
		{
			if (!(i == 0 && files == 0))
				write(1, "\n", 1);
			write(1, dirs[i], str_len(dirs[i]) - 1);
			write(1, ":\n", 2);
		}
		if (handle_arguments(data, dirs[i]))
			return (1);
		i++;
	}
	return (0);
}

int	handle_args(t_data *data, char **files, char **dirs)
{
	if (sort_files(data, files))
		return (freeing(files, -1), freeing(dirs, -1), 1);
	if (sort_files(data, dirs))
		return (freeing(files, -1), freeing(dirs, -1), 1);
	if (output_files_arg(data, files))
		return (freeing(files, -1), freeing(dirs, -1), 1);
	if (handle_dirs(data, dirs, len2d_array(files)))
		return (freeing(files, -1), freeing(dirs, -1), 1);
	return (freeing(files, -1), freeing(dirs, -1), 0);
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
		if (!files)
			return (1);
		dirs = get_files_dirs(data->files, 1);
		if (!dirs)
			return (freeing(dirs, -1), 1);
		if (handle_args(data, files, dirs))
			return (1);
	}
	return (0);
}
