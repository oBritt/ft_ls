/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_addition1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:11:54 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:31:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_space(char *(*func)(char*))
{
	if (func == get_hard_links || func == get_group || func == get_group_numb \
	|| func == get_size_h || func == get_size)
		return (2);
	return (1);
}

int	same_distance(char ***allocated, int max, int i,  char *(*func)(char*))
{
	int		e;
	char	*temp; 

	e = 0;
	max += get_space(func);
	while (allocated[e])
	{
		temp = fill_spaces(allocated[e][i], max);
		if (!temp)
			return (1);
		free(allocated[e][i]);
		allocated[e][i] = temp;
		e++;
	}
	return (0);
}

char	**create_addition(char ***allocated, char **files)
{
	char	**out;
	int		len;

	len = len2d_array(files);
	out = malloc((len + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	len = 0;
	while (files[len])
	{
		out[len] = join_2d_array(allocated[len]);
		if (!out[len])
			return (freeing(out, -1), NULL);
		len++;
	}
	return (out);
}

char	**get_addition(char **files, char ***allocated, \
char *(*operations[])(char *))
{
	int		i;
	int		e;
	char	*temp;
	int		max;

	i = 0;
	while (operations[i])
	{
		e = -1;
		max = 0;
		dprintf(1, "%i", i);
		while (files[++e])
		{
			temp = operations[i](files[e]);
			if (temp == NULL)
			{
				write(1, "Asddas", 4);
				return (NULL);
			}
			if (str_len(temp) > max)
				max = str_len(temp);
			allocated[e][i] = temp;
		}
		if (i != 0)
			if (same_distance(allocated, max, i, operations[i]))
			{
					write(1, "Asddas", 4);
				return (NULL);
			}
		i++;
	}
	return (create_addition(allocated, files));
}
