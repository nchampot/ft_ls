/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:30:41 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/07 16:30:43 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "libft/inc/libft.h"

# define USAGE "usage: ft_ls [-Ralrt] [File...]"

int		parse_args(int ac, char **av, char ***startdirs, char **opts);
int		recursive(char **startdirs, char *opts);
char	**opt_l(char **paths);
char	**lex_sort(char **paths);
char	**r_sort(char **paths);
char	**t_sort(char **paths);
char	**ft_error(char *path);

#endif
