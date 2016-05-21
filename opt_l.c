/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/05/21 20:01:24 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		add_rights(char **buf, t_stat st)
{
	if (S_ISDIR(st.fstat.st_mode))
		ft_addchr(buf, 'd');
	else if (S_ISLNK(st.fstat.st_mode))
		ft_addchr(buf, 'l');
	else if (S_ISCHR(st.fstat.st_mode))
		ft_addchr(buf, 'c');
	else if (S_ISBLK(st.fstat.st_mode))
		ft_addchr(buf, 'b');
	else if (S_ISSOCK(st.fstat.st_mode))
		ft_addchr(buf, 's');
	else if (S_ISFIFO(st.fstat.st_mode))
		ft_addchr(buf, 'p');
	else
		ft_addchr(buf, '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IWUSR) ? 'w' : '-');
	if (st.fstat.st_mode & S_IXUSR)
		ft_addchr(buf, (st.fstat.st_mode & S_ISUID) ? 's' : 'x');
	else
		ft_addchr(buf, (st.fstat.st_mode & S_ISUID) ? 'S' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IWGRP) ? 'w' : '-');
	if (st.fstat.st_mode & S_IXGRP)
		ft_addchr(buf, (st.fstat.st_mode & S_ISGID) ? 's' : 'x');
	else
		ft_addchr(buf, (st.fstat.st_mode & S_ISGID) ? 'S' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IWOTH) ? 'w' : '-');
	if (st.fstat.st_mode & S_IXOTH)
		ft_addchr(buf, (st.fstat.st_mode & S_ISVTX) ? 't' : 'x');
	else
		ft_addchr(buf, (st.fstat.st_mode & S_ISVTX) ? 'T' : '-');
}

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

	buff = ft_strnew(3000);
	if (**buf == 'l')
	{
		if (readlink(path, buff, 3000) >= 0)
		{
			*buf = ft_strjoin(*buf, " -> ");
			*buf = ft_strjoin(*buf, buff);
		}
	}
}

static char		*stat_path(char *path, t_max max)
{
	char		*buf;
	t_stat		st;

	buf = ft_strnew(1);
	if (lstat(path, &st.fstat) < 0)
		return (NULL);
	st.fuid = getpwuid(st.fstat.st_uid);
	st.gid = st.fstat.st_gid;
	st.fgrp = getgrgid(st.gid);
	add_rights(&buf, st);
	ft_addchr(&buf, get_attr(path));
	add_spaces(&buf, max.nlink - nb_digit(st.fstat.st_nlink) + 1);
	buf = ft_strjoin(buf, ft_itoa(st.fstat.st_nlink));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, st.fuid ? st.fuid->pw_name : ft_itoa(st.fstat.st_uid));
	add_spaces(&buf, max.len_pwname - ft_strlen(st.fuid ? st.fuid->pw_name : ft_itoa(st.fstat.st_uid)) + 2);
	buf = ft_strjoin(buf, st.fgrp ? st.fgrp->gr_name : ft_itoa(st.gid));
	add_spaces(&buf, max.len_grname - ft_strlen(st.fgrp ? st.fgrp->gr_name : ft_itoa(st.gid)));
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

	i = 0;
	max = get_max(paths);
	buf = (char**)malloc(sizeof(char*));
	*buf = NULL;
	if (*paths)
		ft_addstr(&buf, get_total(paths));
	while (paths[i])
	{
		ft_addstr(&buf, stat_path(paths[i], max));
		i++;
	}
	return (buf);
}
