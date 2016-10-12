/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:18:03 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 13:19:17 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	struct stat		fstat;
	struct passwd	*fuid;

	if (lstat(path, &fstat) < 0)
		return (-1);
	return (S_ISDIR(fstat.st_mode));
}

int		is_allowed(char *path)
{
	DIR	*dirp;

	errno = 0;
	dirp = opendir(path);
	return (!(errno == EACCES));
}

char	*crop(char *path)
{
	int		len;
	char	*buf;

	if (!path)
		return (NULL);
	len = ft_strlen(path);
	if (path[len - 1] == '/')
		return ("");
	if (len == 1)
		return (path);
	if (path[len - 1] != '/' && ft_strchr(path, '/'))
		return (ft_strrchr(path, '/') + 1);
	else if (path[len - 1] == '/')
		return (ft_strrchr(ft_strsub(path, 0, len - 1), '/') + 1);
	return (path);
}

char	*extend(char *path, char *d_name)
{
	int	is_hdir;

	if (path[ft_strlen(path) - 1] != '/')
		return (ft_strjoin(ft_strjoin(path, "/"), d_name));
	return (ft_strjoin(path, d_name));
}

int		fd_error(char *path)
{
	if (errno == 0)
		return (1);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(crop(path), 2);
	if (errno == EACCES)
		ft_putendl_fd(": Permission denied", 2);
	else if (errno == ENOENT)
		ft_putendl_fd(": No such file or directory", 2);
	else if (errno == ENOTDIR)
		ft_putendl_fd(": Not a directory", 2);
	else
		ft_putendl_fd(": Unkown error", 2);
	errno = 0;
	return (1);
}
