/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:13:23 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/22 16:46:13 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error_not_found(char *path)
{
	write(2, "ls: ", 4);
	write(2, path, str_len(path));
	write(2, ": No such file or directory\n", 28);
}

int	check_if_exists(char *path)
{
	struct stat	buffer;

	if (stat(path, &buffer) == 0)
	{
		return (1);
	}
	return (0);
}

int	handle_file(t_data *data, char *av, int *index)
{
	if (check_if_exists(av))
	{
		data->files[*index] = ft_str_dup(av);
		if (!data->files[*index])
			return (1);
		*index = *index + 1;
	}
	else
		print_error_not_found(av);
	return (0);
}

int	handle_files(t_data *data, char **av, int prev, int ac)
{
	int	current;

	if (prev == ac)
	{
		data->files = NULL;
		return (1);
	}
	data->files = malloc((ac - prev + 1) * sizeof(char *));
	if (!data->files)
		return (1);
	current = 0;
	while (prev < ac)
	{
		if (handle_file(data, av[prev], &current))
			return (freeing(data->files, current), 1);
		prev++;
	}
	data->files[current] = NULL;
	return (0);
}
