/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:18:03 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/12 18:09:40 by nchampot         ###   ########.fr       */
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

char	*crop(char *path)
{
	int		len;
	char	*buf;

	if (!path)
		return (NULL);
	len = ft_strlen(path);
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
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(crop(path), 2);
	if (errno == EACCES)
		ft_putendl_fd(": Permission denied", 2);
	else
		ft_putendl_fd(": No such file or directory", 2);
	return (0);
}
