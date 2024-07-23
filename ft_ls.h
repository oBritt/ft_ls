/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:12:27 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/23 19:43:54 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>


typedef struct s_data
{
	int		option_cr;
	int		option_l;
	int		option_a;
	int		option_r;
	int		option_t;
	int		option_g;
	int		option_ca;
	int		option_f;
	char	**files;

}	t_data;

int			len2d_array(char **s);
int			str_len(char *s);
int			validate_flag(t_data *data, char *s);
int			check_if_flag(char *t);
char		*str_join(char *s1, char *s2);
char		*ft_str_dup(char *s);
int			handle_files(t_data *data, char **av, int prev, int ac);
void		freeing(char **arr, int len);
void		sort_strings(char **arr, int (*func)(char *str1, char *str2));
void		reverse_strings(char **arr);
int			str_compare_sort(char *str1, char *str2);
char		*ft_str_dup_len(char *str, int len);
long long	get_time_created(char *str);
void		ft_memset(void *ptr, int len);
char		*itos(long long numb);
char		**get_files(t_data *data, char *path, long long *blocks);
int			start_ls(t_data *data);
int			str_time_sort(char *str1, char *str2);
long long	get_time_created(char *str);
int			improve_files(char ***files, char *str);
int			is_dir(char *path);
int			handle_option_cr(t_data *data, char **files);
int			handle_arguments(t_data *data, char *str);
int			get_last_app(char *str, char c);
#endif