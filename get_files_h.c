/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:38:34 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 10:44:51 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_valid(t_data *data, char *file)
{
	if (data->option_a)
		return (1);
	if (data->option_ca && !same_strings(file, ".") && \
	!same_strings(file, ".."))
		return (1);
	if (file[0] != '.')
		return (1);
	return (0);
}
