/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:08:28 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 10:07:34 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// implemented -A -f -g -1 -i -m

// l => basic
// r => reversed
// t => sorted by time
// R => recursively opens all of the dirs
// a => shows also files which starts with dot

// A => shows everything except . and ..
// g => l but no owner
// 1 => each is in separate line
// i =>  serial number
// n => makes group and user numbers -l
// S => sorts by size
// s => display how many blocks 
// h => display in kBytes etc
// f => not sorted turns on -a

t_data	*get_data(void)
{
	static t_data	*data;

	return (data);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	ft_memset(&data, sizeof(t_data));
	i = 1;
	while (i < ac && check_if_flag(av[i]))
	{
		if (validate_flag(&data, av[i]))
			return (write(1, "Error unvalid flag\n", 19), 1);
		i++;
	}
	if (handle_files(&data, av, i, ac))
		return (write(1, "Memmory allocation error\n", 25), 1);
	i = start_ls(&data);
	freeing(data.files, -1);
	if (i)
		return (write(1, "Memmory allocation error\n", 25), 1);
	return (0);
}
