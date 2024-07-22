/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:08:28 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/22 16:00:01 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_data	*get_data(void)
{
	static t_data	*data;

	return (data);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
	while (i < ac && check_if_flag(av[i]))
	{
		if (validate_flag(&data, av[i]))
			return (write(1, "Error unvalid flag\n", 19), 1);
		i++;
	}
	return (0);
}
