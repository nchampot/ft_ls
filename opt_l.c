/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/09 04:11:00 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		add_size(char **buf, char *path, struct stat fstat, t_max max)
{
	if (ft_strlen(path) > 3 && ft_strcmp(ft_strsub(path, 0, 4), "/dev") == 0)
	{
		if (S_ISBLK(fstat.st_mode) || S_ISCHR(fstat.st_mode))
		{
			add_spaces(buf, max.maj_size - nb_digit(major(fstat.st_rdev)) + 3);
			*buf = ft_strjoin(*buf, ft_itoa(major(fstat.st_rdev)));
			ft_addchr(buf, ',');
		}
		else
			add_spaces(buf, max.maj_size + 4);
		add_spaces(buf, max.min_size - nb_digit(minor(fstat.st_rdev)) + 1);
		*buf = ft_strjoin(*buf, ft_itoa(minor(fstat.st_rdev)));
	}
	else
	{
		add_spaces(buf, max.st_size - nb_digit(fstat.st_size) + 2);
		*buf = ft_strjoin(*buf, ft_itoa(fstat.st_size));
	}
	ft_addchr(buf, ' ');
}

static void		show_link(char **buf, char *path)
{
	char	*buff;

	buff = ft_strnew(200);
	if (**buf == 'l')
	{
		if (readlink(path, buff, 200) >= 0)
		{
			*buf = ft_strjoin(*buf, " -> ");
			*buf = ft_strjoin(*buf, buff);
		}
	}
}

char			*stat_path(char *path, t_max max)
{
	char		*buf;
	t_stat		st;

	buf = ft_strnew(1);
	st = init_stat(path);
	add_rights(&buf, st);
	ft_addchr(&buf, get_attr(path));
	add_spaces(&buf, max.nlink - nb_digit(st.fstat.st_nlink) + 1);
	buf = ft_strjoin(buf, ft_itoa(st.fstat.st_nlink));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, st.fuid ?\
			st.fuid->pw_name : ft_itoa(st.fstat.st_uid));
	add_spaces(&buf, max.len_pwname - ft_strlen(st.fuid ?\
				st.fuid->pw_name : ft_itoa(st.fstat.st_uid)) + 2);
	buf = ft_strjoin(buf, st.fgrp ?\
			st.fgrp->gr_name : ft_itoa(st.gid));
	add_spaces(&buf, max.len_grname - ft_strlen(st.fgrp ?\
				st.fgrp->gr_name : ft_itoa(st.gid)));
	add_size(&buf, path, st.fstat, max);
	buf = ft_strjoin(buf, get_time(st.fstat.st_mtimespec.tv_sec, path));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_strrchr(path, '/') + 1);
	show_link(&buf, path);
	return (buf);
}

char			**opt_l(char **paths)
{
	char		**buf;
	t_max		max;
	int			i;

	buf = (char**)malloc(sizeof(char*));
	*buf = NULL;
	max = get_max(paths);
	if (paths[1])
		ft_addstr(&buf, get_total(paths));
	i = 0;
	while (paths[i])
		ft_addstr(&buf, stat_path(paths[i++], max));
	return (buf);
}
