/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:18:03 by nchampot          #+#    #+#             */
/*   Updated: 2016/05/30 13:45:56 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	struct stat		fstat;
	struct passwd	*fuid;

	if (lstat(path, &fstat) < 0)
		return (0);
	return (S_ISDIR(fstat.st_mode));
}

static int	is_homedir(char *path)
{
	struct stat		fstat;
	struct passwd	*fuid;
	int				ret;

	if (lstat(path, &fstat) < 0)
		return (0);
	fuid = getpwuid(fstat.st_uid);
	if (path[ft_strlen(path) - 1] == '/')
		ret = 2;
	else
		ret = 1;
	if (ft_strlen(path) != ft_strlen(fuid->pw_name) + 6 + ret)
		return (0);
	if (ft_strcmp(ft_strsub(path, 0, 7), "/Users/") != 0) 
		return (0);
	if (ft_strcmp(ft_strsub(path, 7, ft_strlen(fuid->pw_name)), fuid->pw_name) != 0)
		return (0);
	return (ret);
}

char	*crop(char *path)
{
	int	len;

	if (!path)
		return (NULL);
	len = ft_strlen(path);
	if (path[len - 1] != '/')
		return (ft_strrchr(path, '/') + 1);
	if (ft_strcmp(ft_strsub(path, len - 2, 2), "//") == 0)
		return (ft_strrchr(ft_strsub(path, 0, len - 2), '/') + 1);
	return (ft_strrchr(ft_strsub(path, 0, len - 1), '/') + 1);
}

char	*extend(char *path, char *d_name)
{
	int	is_hdir;

	if ((is_hdir = is_homedir(path)) == 1)
		return (ft_strjoin(ft_strjoin(path, "//"), d_name));
	if (path[ft_strlen(path) - 1] != '/' || is_hdir == 2)
		return (ft_strjoin(ft_strjoin(path, "/"), d_name));
	return (ft_strjoin(path, d_name));
}

int	fd_error(char *path)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(crop(path), 2);
	if (errno == EACCES)
		ft_putendl_fd(": Permission denied", 2);
	else
		ft_putendl_fd(": No such file or directory", 2);
	return (0);
}
