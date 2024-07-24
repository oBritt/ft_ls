/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:18:31 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 12:57:20 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long	get_time_created(char *str)
{
	struct stat	file_stat;

	if (stat(str, &file_stat) < 0)
		return (-1);
	return ((long long)file_stat.st_mtime);
}

char	*get_string_created(char *path)
{
	time_t		created_time;
	char		*output;
	char		*temp;

	created_time = (time_t)get_time_created(path);
	if (created_time == -1)
		return (NULL);
	temp = ctime(&created_time);
	if (!temp)
		return (NULL);
	output = ft_str_dup_len(temp + 4, 12);
	free(temp);
	if (!output)
		return (NULL);
	return (output);
}

static void	fill_with_dashes(char *output)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (output[i] == 0)
			output[i] = '-';
		i++;
	}
}

void	get_perm(char *output, mode_t mode)
{
	if (S_ISDIR(mode))
		output[0] = 'd';
	if (mode & S_IRUSR)
		output[1] = 'r';
	if (mode & S_IWUSR)
		output[2] = 'w';
	if (mode & S_IXUSR)
		output[3] = 'x';
	if (mode & S_IRGRP)
		output[4] = 'r';
	if (mode & S_IWGRP)
		output[5] = 'w';
	if (mode & S_IXGRP)
		output[6] = 'x';
	if (mode & S_IROTH)
		output[7] = 'r';
	if (mode & S_IWOTH)
		output[8] = 'w';
	if (mode & S_IXOTH)
		output[9] = 'x';
	fill_with_dashes(output);
}

char	*get_permissions(char *path)
{
	char		*output;
	struct stat	file_stat;
	struct stat	file_lstat;

	if (stat(path, &file_stat) < 0)
		return (NULL);
	if (lstat(path, &file_lstat) < 0)
		return (NULL);
	output = malloc(11 * sizeof(char));
	if (!output)
		return (NULL);
	ft_memset(output, 11);
	if (S_ISLNK(file_lstat.st_mode))
	{
		get_perm(output, file_lstat.st_mode);
		output[0] = 'l';
	}
	else
	{
		get_perm(output, file_stat.st_mode);
	}
	return (output);
}