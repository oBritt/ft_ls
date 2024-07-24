/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_cr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:07:00 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 18:40:50 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_amount_of_dirs(char **files, int find)
{
	int	i;
	int	counter;
	int	temp;

	i = 0;
	counter = 0;
	while (files[i])
	{
		temp = is_dir(files[i]);
		if (temp == -1)
			return (-1);
		else if (temp == find)
			counter++;
		i++;
	}
	return (counter);
}

static int	helper_get_dirs(char **dirs, char **files, int i, int *counter)
{
	int	len;

	len = str_len(files[i]);
	if (files[i][len - 1] != '/')
	{
		dirs[*counter] = str_join(files[i], "/");
		if (!dirs[*counter])
			return (freeing(dirs, *counter), 1);
	}
	else
	{
		dirs[*counter] = ft_str_dup(files[i]);
		if (!dirs[*counter])
			return (freeing(dirs, *counter), 1);
	}
	*counter = *counter +1;
	return (0);
}

char	**get_files_dirs(char **files, int find)
{
	int		len;
	char	**dirs;
	int		i;
	int		temp;
	int		counter;

	len = get_amount_of_dirs(files, find);
	if (len == -1)
		return (NULL);
	dirs = malloc((len + 1) * sizeof(char *));
	if (!dirs)
		return (NULL);
	i = -1;
	counter = 0;
	while (files[++i])
	{
		temp = is_dir(files[i]);
		if (temp == -1)
			return (freeing(dirs, i), NULL);
		if (temp == find)
			if (helper_get_dirs(dirs, files, i, &counter))
				return (NULL);
	}
	dirs[counter] = NULL;
	return (dirs);
}

int	handle_option_cr(t_data *data, char **files)
{
	char	**dirs;
	int		i;

	dirs = get_files_dirs(files, 1);
	if (!dirs)
		return (1);
	i = 0;
	while (dirs[i])
	{
		if (!same_strings(dirs[i] + get_prev_last_app(dirs[i], '/') + 1, "./") \
		&& !same_strings(dirs[i] + get_prev_last_app(dirs[i], '/') + 1, "../"))
		{
			write(1, "\n", 1);
			write(1, dirs[i], str_len(dirs[i]) - 1);
			write(1, ":\n", 2);
			if (handle_arguments(data, dirs[i]))
				return (freeing(dirs, -1), 1);
		}
		i++;
	}
	freeing(dirs, -1);
	return (0);
}
