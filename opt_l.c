/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:00:37 by nchampot          #+#    #+#             */
/*   Updated: 2016/03/21 06:24:39 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	opt_l(char *fd, struct stat filestat, struct group *filegroup)
{
	typedef struct passwd    t_passwd;
	char                    *mtime;
	t_passwd                *fileuid;
	gid_t                    gid;

	if (lstat(fd, &filestat) < 0)
		return (1);
	fileuid = getpwuid(filestat.st_uid);
	gid = getgid();
	filegroup = getgrgid(gid);
	if (S_ISDIR(filestat.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(filestat.st_mode))
		ft_putchar('l');
	else
		ft_putchar('-');
	ft_putchar((filestat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
	ft_putnbr(filestat.st_nlink);
	ft_putchar(' ');
	ft_putstr(fileuid->pw_name);
	ft_putstr("  ");
	ft_putstr(filegroup->gr_name);
	ft_putstr("  ");
	ft_putnbr(filestat.st_size);
	ft_putchar(' ');
	mtime = ctime(&(filestat.st_mtimespec.tv_sec));
	write(1, mtime + 4, 12);
	ft_putchar(' ');
	ft_putstr(ft_strrchr(fd, '/') + 1);
	return (0);
}
