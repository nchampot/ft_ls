/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:19:17 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/09 04:48:20 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_devmax(char *path, t_max *max, t_stat st)
{
	int pw_len;
	int gr_len;

	if (ft_strlen(path) > 3 && ft_strcmp(ft_strsub(path, 0, 4), "/dev") == 0)
	{
		if (max->maj_size < nb_digit(major(st.fstat.st_rdev)))
			max->maj_size = nb_digit(major(st.fstat.st_rdev));
		if (max->min_size < nb_digit(minor(st.fstat.st_rdev)))
			max->min_size = nb_digit(minor(st.fstat.st_rdev));
	}
	pw_len = st.fuid ? ft_strlen(st.fuid->pw_name) : nb_digit(st.fstat.st_uid);
	if (pw_len > max->len_pwname)
		max->len_pwname = pw_len;
	gr_len = st.fgrp ? ft_strlen(st.fgrp->gr_name) : nb_digit(st.gid);
	if (gr_len > max->len_grname)
		max->len_grname = gr_len;
}

t_max			get_max(char **paths)
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
		get_devmax(paths[i], &max, st);
		if (max.nlink < nb_digit(st.fstat.st_nlink))
			max.nlink = nb_digit(st.fstat.st_nlink);
		i++;
	}
	return (max);
}

char			*get_total(char **paths)
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

char			*get_time(time_t mtime, char *path)
{
	char	*buf;
	time_t	t;
	char	*date;

	date = ctime(&mtime);
	if (time(&t) - mtime > 15768000 || mtime > t)
	{
		buf = ft_strsub(date, 4, 7);
		ft_addchr(&buf, ' ');
		return (ft_strjoin(buf, ft_strsub(date, 20, 4)));
	}
	return (ft_strsub(date, 4, 12));
}

char			get_attr(char *path)
{
	if (listxattr(path, "0", 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	if (acl_get_file(path, ACL_TYPE_EXTENDED) > 0)
		return ('+');
	return (' ');
}
