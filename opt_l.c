/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/15 18:48:07 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_max	get_max(char **paths)
{
	int			i;
	t_stat		st;
	t_max		max;

	i = 0;
	max = init_max();
	while (paths[i])
	{
		if (lstat(paths[i], &st.fstat) < 0)
			exit(-1);
		st.fuid = getpwuid(st.fstat.st_uid);
		st.fgrp = getgrgid(st.fstat.st_gid);
		if (max.st_size < nb_digit(st.fstat.st_size))
			max.st_size = nb_digit(st.fstat.st_size);
	if (ft_strlen(paths[i]) > 3 && ft_strcmp(ft_strsub(paths[i], 0, 4), "/dev") == 0)
		{
			if (max.major_size < nb_digit(major(st.fstat.st_rdev)))
				max.major_size = nb_digit(major(st.fstat.st_rdev));
			if (max.minor_size < nb_digit(minor(st.fstat.st_rdev)))
				max.minor_size = nb_digit(minor(st.fstat.st_rdev));
		}
		if (max.nlink < nb_digit(st.fstat.st_nlink))
			max.nlink = nb_digit(st.fstat.st_nlink);
		if (ft_strlen(st.fuid->pw_name) > max.len_pwname)
			max.len_pwname = ft_strlen(st.fuid->pw_name);
		if (ft_strlen(st.fgrp->gr_name) > max.len_grname)
			max.len_grname = ft_strlen(st.fgrp->gr_name);
		i++;
	}
	return (max);
}

static char		*get_total(char **paths)
{
	int			i;
	struct stat	fstat;
	int			total;
	char		*buf;

	i = 0;
	total = 0;
	while (paths[i])
	{
		if (lstat(paths[i], &fstat) < 0)
			exit(0);
		total += fstat.st_blocks;
		i++;
	}
	return (ft_strjoin("total ", ft_itoa(total)));
}

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
	ft_addchr(buf, (st.fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_addchr(buf, (st.fstat.st_mode & S_IXOTH) ? 'x' : '-');
}

static void		add_size(char **buf, char *path, struct stat fstat, t_max max)
{
	if (ft_strlen(path) > 3 && ft_strcmp(ft_strsub(path, 0, 4), "/dev") == 0)
	{
		add_spaces(buf, max.major_size - nb_digit(major(fstat.st_rdev)) + 3);
		if (S_ISBLK(fstat.st_mode) || S_ISCHR(fstat.st_mode))
		{
			*buf = ft_strjoin(*buf, ft_itoa(major(fstat.st_rdev)));
			ft_addchr(buf, ',');
		}
		add_spaces(buf, max.minor_size - nb_digit(minor(fstat.st_rdev)) + 1);
		*buf = ft_strjoin(*buf, ft_itoa(minor(fstat.st_rdev)));
	}
	else
	{
		add_spaces(buf, max.st_size - nb_digit(fstat.st_size) + 2);
		*buf = ft_strjoin(*buf, ft_itoa(fstat.st_size));
	}
	ft_addchr(buf, ' ');
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
	add_spaces(&buf, max.nlink - nb_digit(st.fstat.st_nlink) + 2);
	buf = ft_strjoin(buf, ft_itoa(st.fstat.st_nlink));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, st.fuid->pw_name);
	add_spaces(&buf, max.len_pwname - ft_strlen(st.fuid->pw_name) + 2);
	buf = ft_strjoin(buf, st.fgrp->gr_name);
	add_spaces(&buf, max.len_grname - ft_strlen(st.fgrp->gr_name));
	add_size(&buf, path, st.fstat, max);
	st.mtime = ctime(&(st.fstat.st_mtimespec.tv_sec));
	buf = ft_strjoin(buf, ft_strsub(st.mtime, 4, 12));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_strrchr(path, '/') + 1);
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
