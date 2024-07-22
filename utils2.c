/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:36:58 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/22 18:38:40 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_memset(void *ptr, int len)
{
	char	*ptr_char;
	int		i;

	ptr_char = (char *)ptr;
	i = 0;
	while (i < len)
	{
		ptr_char[i] = 0;
		i++;
	}
}
