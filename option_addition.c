/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_addition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:28 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:37:40 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	move_stuff(char *(*operations[])(char *))
{
	int	ptr1;
	int	ptr2;

	ptr1 = 0;
	ptr2 = 0;
	while (ptr1 < 9)
	{
		if (operations[ptr1])
		{
			operations[ptr2] = operations[ptr1];
			ptr2++;
		}
		ptr1++;
	}
	operations[ptr2] = NULL;
	return (ptr2);
}

void	fill_nulls(char *(*operations[])(char *))
{
	int	i;

	i = 0;
	while (i < 9)
	{
		operations[i] = NULL;
		i++;
	}
}

void	fill_operations(char *(*operations[])(char *), t_data *data)
{
	fill_nulls(operations);
	if (data->option_l)
	{
		operations[2] = get_permissions;
		operations[3] = get_hard_links;
		operations[4] = get_user;
		operations[5] = get_group;
		operations[6] = get_size;
		operations[7] = get_string_created;
		if (data->option_n)
		{
			operations[4] = get_user_numb;
			operations[5] = get_group_numb;
		}
		if (data->option_g)
			operations[4] = NULL;
		if (data->option_h)
			operations[6] = get_size_h;
	}
	if (data->option_i)
		operations[0] = get_files_serial_nbr;
	if (data->option_s)
		operations[1] = get_files_block;
	operations[8] = NULL;
}

char	***allocate(int len, int len2, int e)
{
	char	***output;
	int		i;

	output = malloc((len + 1) * sizeof(char **));
	if (!output)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = malloc((len2 + 1) * sizeof(char *));
		if (!output[i])
		{
			while (e < i)
			{
				free(output[e]);
				e++;
			}
			return (free(output), NULL);
		}
		output[i][len2] = NULL;
		i++;
	}
	output[i] = NULL;
	return (output);
}

char	**option_addition(t_data *data, char **files)
{
	char	*(*operations[9])(char *);
	int		len2;
	int		len;
	char	***allocated;
	char	**addition;

	fill_operations(operations, data);
	len2 = move_stuff(operations);
	len = len2d_array(files);
	allocated = allocate(len, len2, 0);
	if (!allocated)
		return (NULL);
	addition = get_addition(files, allocated, operations);
	super_freeing(allocated);
	if (!addition)
		return (NULL);
	return (addition);
}
