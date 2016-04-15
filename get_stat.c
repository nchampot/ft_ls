/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:19:17 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/15 20:24:10 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_devmax(char *path, t_max *max, t_stat st)
{
	if (ft_strlen(path) > 3 && ft_strcmp(ft_strsub(path, 0, 4), "/dev") == 0)
	{
		if (max->maj_size < nb_digit(major(st.fstat.st_rdev)))
			max->maj_size = nb_digit(major(st.fstat.st_rdev));
		if (max->min_size < nb_digit(minor(st.fstat.st_rdev)))
			max->min_size = nb_digit(minor(st.fstat.st_rdev));
	}
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
		if (ft_strlen(st.fuid->pw_name) > max.len_pwname)
			max.len_pwname = ft_strlen(st.fuid->pw_name);
		if (ft_strlen(st.fgrp->gr_name) > max.len_grname)
			max.len_grname = ft_strlen(st.fgrp->gr_name);
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
