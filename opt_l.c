/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/05 12:45:03 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	nb_digit(int	nb)
{
	int	count;
	int	buf;

	count = 1;
	buf = nb;
	while (buf > 9)
	{
		buf = buf / 10;
		count++;
	}
	return (count);
}

static	void	get_max(char **paths, int *max_nlink, int *max_size, int *max_vaniquertamere)
{
	int		i;
	struct stat	filestat;
	struct passwd	*fileuid;

	i = 0;
	while (paths[i])
	{
		if (lstat(paths[i], &filestat) < 0)
			return ;
		fileuid = getpwuid(filestat.st_uid);
		if ((*max_size) < nb_digit(filestat.st_size))
			(*max_size) = nb_digit(filestat.st_size);
		if ((*max_nlink) < nb_digit(filestat.st_nlink))
			(*max_nlink) = nb_digit(filestat.st_nlink);
		if (ft_strlen(fileuid->pw_name) > (*max_vaniquertamere))
			(*max_vaniquertamere) = ft_strlen(fileuid->pw_name);
		i++;
	}
	(*max_nlink) += 2;
	(*max_size) += 2;
	(*max_vaniquertamere) += 2;
}


static	char	*get_total(char **paths)
{
	int		i;
	struct stat	filestat;
	int				total;
	char	*buf;

	i = 0;
	total = 0;
	while (paths[i])
	{
		if (lstat(paths[i], &filestat) < 0)
			return (NULL);
		total += filestat.st_blocks;
		i++;
	}
	return (ft_strjoin("total ", ft_itoa(total)));
}

static char	*stat_path(char *path, int	max_nlink, int max_size, int max_vaniquertamere)
{
	char                    *mtime;
	struct passwd                *fileuid;
	gid_t                    gid;
	char					*buf;
	struct stat				filestat;
	struct group			*filegroup;
	int						i;

	buf = ft_strnew(1);
	if (lstat(path, &filestat) < 0)
		return (NULL);
	fileuid = getpwuid(filestat.st_uid);
	gid = filestat.st_gid;
	filegroup = getgrgid(gid);
	if (S_ISDIR(filestat.st_mode))
		ft_addchr(&buf, 'd');
	else if (S_ISLNK(filestat.st_mode))
		ft_addchr(&buf, 'l');
	else
		ft_addchr(&buf, '-');
	ft_addchr(&buf, (filestat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IROTH) ? 'r' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_addchr(&buf, (filestat.st_mode & S_IXOTH) ? 'x' : '-');
	i = 0;
	while (max_nlink - nb_digit(filestat.st_nlink) > i++)
		ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_itoa(filestat.st_nlink));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, fileuid->pw_name);
	i = 0;
	while (max_vaniquertamere - ft_strlen(fileuid->pw_name) > i++)
		ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, filegroup->gr_name);
	i = 0;
	while (max_size - nb_digit(filestat.st_size) > i++)
		ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_itoa(filestat.st_size));
	ft_addchr(&buf, ' ');
	mtime = ctime(&(filestat.st_mtimespec.tv_sec));
	buf = ft_strjoin(buf, ft_strsub(mtime, 4, 12));
	ft_addchr(&buf, ' ');
	buf = ft_strjoin(buf, ft_strrchr(path, '/') + 1);
	return (buf);
}
// creer un nouveau tableau de stats a partir des chemins puis renvoie le tableau apres le formatage en colonne
char	**opt_l(char **paths)
{
	char	**buf;
	int		max_nlink;
	int		max_size;
	int		max_vaniquertamere;
	int		i;

	max_nlink = 0;
	max_size = 0;
	max_vaniquertamere = 0;
	i = 0;
	buf = (char**)malloc(sizeof(char*));
	*buf = NULL;
	ft_addstr(&buf, get_total(paths));
	get_max(paths, &max_nlink, &max_size, &max_vaniquertamere);
	while(paths[i])
	{
		ft_addstr(&buf, stat_path(paths[i], max_nlink, max_size, max_vaniquertamere));
		i++;
	}
	return (buf);
}
