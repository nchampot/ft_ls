/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:30:41 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 16:44:41 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "libft/inc/libft.h"
# include <errno.h>

# define USAGE "usage: ft_ls [-Ralrt] [File...]"

typedef struct		s_stat
{
	struct passwd	*fuid;
	gid_t			gid;
	struct stat		fstat;
	struct group	*fgrp;
}					t_stat;

typedef struct		s_max
{
	int				st_size;
	int				nlink;
	int				len_pwname;
	int				len_grname;
	int				min_size;
	int				maj_size;
}					t_max;

typedef struct		s_dir
{
	struct dirent	*dp;
	DIR				*dirp;
}					t_dir;

t_max				get_max(char **paths);
char				*get_time(time_t mtime, char *path);
char				*get_total(char **paths);
char				get_attr(char *path);
int					parse_args(int ac, char **av, char ***a, char **opts);
int					recursive(char **startdirs, char *opts);
char				**opt_l(char **paths);
void				add_spaces(char	**buf, int nb_space);
void				add_rights(char **buf, t_stat st);
int					nb_digit(int nb);
char				**r_sort(char **paths);
char				**t_sort(char **paths);
char				**l_sort(char **paths);
char				**ft_error(char *path);
int					fd_error(char *path);
t_max				init_max(void);
t_stat				init_stat(char *path);
char				*crop(char *path);
char				*extend(char *path, char *d_name);
int					is_dir(char *path);

#endif
