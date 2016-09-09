/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:16:55 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/09 00:38:09 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_type(t_stat st)
{
	if (S_ISDIR(st.fstat.st_mode))
		return ('d');
	else if (S_ISLNK(st.fstat.st_mode))
		return ('l');
	else if (S_ISCHR(st.fstat.st_mode))
		return ('c');
	else if (S_ISBLK(st.fstat.st_mode))
		return ('b');
	else if (S_ISSOCK(st.fstat.st_mode))
		return ('s');
	else if (S_ISFIFO(st.fstat.st_mode))
		return ('p');
	return ('-');
}

int		is_slink(char *path)
{
	struct stat	fstat;

	if (lstat(path, &fstat) < 0)
		return (1);
	if (S_ISDIR(fstat.st_mode))
		return (0);
	return (1);
}

void		add_rights(char **buf, t_stat st)
{
	ft_addchr(buf, get_type(st));
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

t_stat		init_stat(char *path)
{
	t_stat	st;

	if (lstat(path, &st.fstat) < 0)
		return (st);
	st.fuid = getpwuid(st.fstat.st_uid);
	st.gid = st.fstat.st_gid;
	st.fgrp = getgrgid(st.gid);
	return (st);
}
