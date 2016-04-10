/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/07 20:16:37 by pghassem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_max	get_max(char **paths)
{
	int		i;
	t_stat		st;
	t_max		max;

	i = 0;
	max.st_size = 0;
	max.nlink = 0;
	max.len_pwname = 0;
	max.len_grname = 0;
	while (paths[i])
	{
		if (lstat(paths[i], &st.fstat) < 0)
			exit(-1);
		st.fuid = getpwuid(st.fstat.st_uid);
		st.fgrp = getgrgid(st.fstat.st_gid);
		if (max.st_size < nb_digit(st.fstat.st_size))
			max.st_size = nb_digit(st.fstat.st_size);
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

static char	*get_total(char **paths)
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

static void	add_rights(char	**buf, t_stat st)
{
	if (S_ISDIR(st.fstat.st_mode))
		ft_addchr(buf, 'd');
	else if (S_ISLNK(st.fstat.st_mode))
		ft_addchr(buf, 'l');
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

static char	*stat_path(char *path, t_max max)
{
	char	*buf;
	t_stat	st;

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
	add_spaces(&buf, max.st_size - nb_digit(st.fstat.st_size) + 2);
	buf = ft_strjoin(buf, ft_itoa(st.fstat.st_size));
	ft_addchr(&buf, ' ');
	st.mtime = ctime(&(st.fstat.st_mtimespec.tv_sec));
	buf = ft_strjoin(buf, ft_strsub(st.mtime, 4, 12));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_strrchr(path, '/') + 1);
	return (buf);
}

char		**opt_l(char **paths)
{
	char	**buf;
	t_max	max;
	int	i;

	i = 0;
	max = get_max(paths);
	buf = (char**)malloc(sizeof(char*));
	*buf = NULL;
	ft_addstr(&buf, get_total(paths));
	while (paths[i])
	{
		ft_addstr(&buf, stat_path(paths[i], max));
		i++;
	}
	return (buf);
}
