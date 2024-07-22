/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:12:27 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/22 16:00:18 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>


typedef struct s_data
{
	int		option_cr;
	int		option_l;
	int		option_a;
	int		option_r;
	int		option_t;
	int		option_g;

	char	**files;

}	t_data;

int	len2d_array(char **s);
int	str_len(char *s);
int	validate_flag(t_data *data, char *s);
int	check_if_flag(char *t);

#endif