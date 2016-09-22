/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:30:41 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/22 08:25:03 by nchampot         ###   ########.fr       */
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

# define RED		"\x1B[31m"
# define BRED		"\x1B[1;31m"
# define GREEN		"\x1B[32m"
# define BGREEN		"\x1B[1;32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define BMAGENTA	"\x1B[1;35m"
# define CYAN		"\x1B[36m"
# define BCYAN		"\x1B[1;36m"

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

char				*stat_path(char *path, t_max max);
void				free_stuff(char **stuff);
char				**get_next_dirs(char *current, char *opts);
void				print_all(char **paths, char *opts);
int					is_allowed(char *path);
int					is_slink(char *path);
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
int					is_file(char *name);
char				**extract_files(char **startdirs, int *count);

#endif
