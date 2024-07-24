/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ls_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:52 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 18:42:49 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total(t_data *data, long long blocks)
{
	if (data->option_l)
	{
		write(1, "total ", 6);
		ft_put_nbr(blocks);
		write(1, "\n", 1);
	}
}

void	output_addition(char **addition, int i)
{
	int	len;

	len = str_len(addition[i]);
	write(1, addition[i], len);
	if (len)
		write(1, " ", 1);
	free(addition[i]);
}

void	output_file(char **files, int i, int len, char *sep)
{
	int	ind;

	ind = get_last_app(files[i], '/');
	write(1, &files[i][ind + 1], str_len(files[i]) - ind - 1);
	if (i != len - 1)
		write(1, sep, str_len(sep));
}

int	output_files_arg(t_data *data, char **files)
{
	int		i;
	char	sep[10];
	int		len;
	char	**addition;

	improv_files(files);
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
			write(1, files[i], str_len(files[i]));
			i++;
		}
		write(1, "\n", 1);
	}
	return (free(addition), 0);
}

void	improv_files(char **files)
{
	int	i;
	int	len;

	i = 0;
	while (files[i])
	{
		len = str_len(files[i]);
		if (files[i][len - 1] == '/')
			files[i][len - 1] = 0;
		i++;
	}
}