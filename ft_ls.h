/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:12:27 by obrittne          #+#    #+#             */
/*   Updated: 2024/07/24 15:18:24 by obrittne         ###   ########.fr       */
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
	int		option_1;
	int		option_i;
	int		option_n;
	int		option_cs;
	int		option_s;
	int		option_h;
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
int			sort_strings(char **arr, int (*func)(char *str1, char *str2));
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
char		**get_files_dirs(char **files, int find);
int			same_strings(char *str1, char *str2);
int			get_prev_last_app(char *str, char c);
int			is_valid(t_data *data, char *file);
void		swap_pointers(char **str1, char **str2);
int			sort_files(t_data *data, char **files);
long long	get_size_numb(char *path);
void		ft_put_nbr(long long n);
char		*get_files_serial_nbr(char *path);
char		*get_files_block(char *path);
char		*get_permissions(char *path);
char		*get_hard_links(char *path);
char		*get_user(char *path);
char		*get_user_numb(char *path);
char		*get_group_numb(char *path);
char		*get_group(char *path);
char		*get_size(char *path);
char		*get_string_created(char *path);
char		*get_size_h(char *path);
void		super_freeing(char ***arr);
char		**get_addition(char **files, char ***allocated, \
char *(*operations[])(char *));
char		*fill_spaces(char *str, int len);
char		*join_2d_array(char **arr);
char		**option_addition(t_data *data, char **files);
#endif