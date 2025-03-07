/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_files2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:12:07 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 17:12:13 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_hard_links(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) < 0)
	{
		return (NULL);
	}
	return (itos((long long)file_stat.st_nlink));
}

char	*get_user(char *path)
{
	struct stat		file_stat;
	struct passwd	*pwd;
	char			*out;

	if (stat(path, &file_stat) < 0)
	{
		return (NULL);
	}
	pwd = getpwuid(file_stat.st_uid);
	if (!pwd)
		return (NULL);
	out = ft_str_dup(pwd->pw_name);
	if (!out)
		return (NULL);
	return (out);
}

char	*get_group(char *path)
{
	struct group	*grp;
	struct stat		file_stat;
	char			*out;

	if (stat(path, &file_stat) < 0)
		return (NULL);
	grp = getgrgid(file_stat.st_gid);
	if (!grp)
		return (NULL);
	out = ft_str_dup(grp->gr_name);
	if (!out)
		return (NULL);
	return (out);
}

long long	get_size_numb(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) < 0)
		return (-1);
	return ((long long)file_stat.st_size);
}

char	*get_size(char *path)
{
	char		*out;
	long long	value;

	value = get_size_numb(path);
	if (value == -1)
		return (NULL);
	out = itos(value);
	if (!out)
		return (NULL);
	return (out);
}
