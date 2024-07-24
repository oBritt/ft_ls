/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:49:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 17:12:22 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_blocks(char *path, char *name, long long *blocks)
{
	char		*full_path;
	struct stat	file_stat;

	full_path = str_join(path, name);
	if (!full_path)
		return (1);
	if (lstat(full_path, &file_stat) < 0)
		return (free(full_path), 1);
	free(full_path);
	*blocks += (long long)file_stat.st_blocks;
	return (0);
}

int	amount_of_files(t_data *data, char *path, int counter, long long *blocks)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir(path);
	if (!dir)
		return (-1);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (is_valid(data, entry->d_name))
		{
			if (get_blocks(path, entry->d_name, blocks))
			{
				closedir(dir);
				return (-1);
			}
			counter++;
		}
	}
	closedir(dir);
	return (counter);
}

static int	helper_files(t_data *data, char *path, char **arr, int counter)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir(path);
	if (!dir)
		return (1);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (is_valid(data, entry->d_name))
		{
			arr[counter] = ft_str_dup(entry->d_name);
			if (!arr[counter])
			{
				closedir(dir);
				return (1);
			}
			counter++;
		}
	}
	closedir(dir);
	arr[counter] = NULL;
	return (0);
}

char	**get_files(t_data *data, char *path, long long *blocks)
{
	char			**arr;
	int				counter;

	counter = amount_of_files(data, path, 0, blocks);
	if (counter == -1)
		return (NULL);
	arr = malloc((counter + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (helper_files(data, path, arr, 0))
		return (freeing(arr, -1), NULL);
	return (arr);
}

int	improve_files(char ***files, char *str)
{
	char	**original;
	char	**new_files;
	int		i;

	original = *files;
	new_files = malloc((len2d_array(original) + 1) * sizeof(char *));
	if (!new_files)
		return (1);
	i = 0;
	while (original[i])
	{
		new_files[i] = str_join(str, original[i]);
		if (!new_files[i])
			return (freeing(new_files, i), 1);
		i++;
	}
	new_files[i] = NULL;
	freeing(original, -1);
	*files = new_files;
	return (0);
}
