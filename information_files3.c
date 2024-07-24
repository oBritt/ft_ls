/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_files3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:41:55 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 17:12:10 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_files_serial_nbr(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) != 0)
		return (NULL);
	return (itos((long long) file_stat.st_ino));
}

char	*get_files_block(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) != 0)
		return (NULL);
	return (itos((long long) file_stat.st_blocks));
}

char	*get_user_numb(char *path)
{
	struct stat		file_stat;

	if (stat(path, &file_stat) < 0)
	{
		return (NULL);
	}
	return (itos((long long)file_stat.st_uid));
}

char	*get_group_numb(char *path)
{
	struct stat		file_stat;

	if (stat(path, &file_stat) < 0)
		return (NULL);
	return (itos((long long)file_stat.st_gid));
}
