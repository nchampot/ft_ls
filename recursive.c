/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 18:43:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/05/20 17:21:17 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	printer(char **buff, char *opts)
{
	int		i;
	char	*buf;

	i = 0;
	while (buff[i])
	{
		if (!ft_strchr(opts, 'l'))
			buf = ft_strdup(ft_strrchr(buff[i], '/') + 1);
		else
			buf = buff[i];
		ft_putstr(buf);
		if (!ft_strchr(opts, 'l'))
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
		free(buf);
	}
}

static void	print_all(char **paths, char *opts)
{
	char	**buff;

	buff = lex_sort(paths);
	if (ft_strchr(opts, 't') != NULL)
		buff = t_sort(buff);
	if (ft_strchr(opts, 'r') != NULL)
		buff = r_sort(buff);
	if (ft_strchr(opts, 'l') != NULL)
		buff = opt_l(buff);
	printer(buff, opts);
	if (!ft_strchr(opts, 'l'))
		ft_putchar('\n');
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

static int	add_path(char ***p, char ***ret, char *opts, char *path)
{
	t_dir	d;
	int	is_hdir;

	if ((d.dirp = opendir(path)) == NULL)
		return (fd_error(path));
	while ((d.dp = readdir(d.dirp)) != NULL)
	{
		if (!ft_strchr(opts, 'a') && (d.dp->d_name)[0] == '.')
			continue;

		if ((is_hdir = is_homedir(path)) == 1)
		{
			ft_addstr(p, ft_strjoin(ft_strjoin(path, "//"), d.dp->d_name));
			if (d.dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL
			&& ft_strcmp(d.dp->d_name, ".") && ft_strcmp(d.dp->d_name, ".."))
				ft_addstr(ret, ft_strjoin(ft_strjoin(path, "/"), d.dp->d_name));
		}
		else if (path[ft_strlen(path) - 1] != '/' || is_hdir == 2)
		{
			ft_addstr(p, ft_strjoin(ft_strjoin(path, "/"), d.dp->d_name));
			if (d.dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL
			&& ft_strcmp(d.dp->d_name, ".") && ft_strcmp(d.dp->d_name, ".."))
				ft_addstr(ret, ft_strjoin(ft_strjoin(path, "/"), d.dp->d_name));
		}
		else
		{
			ft_addstr(p, ft_strjoin(path, d.dp->d_name));
			if (d.dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL
			&& ft_strcmp(d.dp->d_name, ".") && ft_strcmp(d.dp->d_name, ".."))
				ft_addstr(ret, ft_strjoin(path, d.dp->d_name));
		}
	}
	(void)closedir(d.dirp);
	return (1);
}

static char	**show_dir(char *path, char *opts)
{
	char			**paths;
	char			**ret;

	paths = (char **)malloc(sizeof(char*));
	*paths = NULL;
	ret = (char **)malloc(sizeof(char*));
	*ret = NULL;
	if (!add_path(&paths, &ret, opts, path))
		return (NULL);
	print_all(paths, opts);
	return (ret);
}

int			recursive(char **startdirs, char *opts)
{
	int			i;
	char		**buf;
	static int	count = 0;

	i = 0;
	count++;
	while (startdirs[i])
	{
		if (count > 1 || (count == 1 && startdirs[1] != NULL))
		{
			if (count > 1)
				ft_putchar('\n');
			ft_putstr(ft_strjoin(startdirs[i], ":\n"));
		}
		/// faire en sorte que le tri prenne en compte tout le path et pas uniquement le nom
		if ((buf = lex_sort(show_dir(startdirs[i], opts))) != NULL)
		{
			if (ft_strchr(opts, 't') != NULL)
				buf = t_sort(buf);
			if (ft_strchr(opts, 'r') != NULL)
				buf = r_sort(buf);
			recursive(buf, opts);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
