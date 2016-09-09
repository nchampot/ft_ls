/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 18:43:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/09 04:48:43 by nchampot         ###   ########.fr       */
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
			buf = ft_strdup(crop(buff[i]));
		else
			buf = buff[i];
		if (!ft_strchr(opts, 'G'))
			ft_putstr(buf);
		else if (i % 2 == 0)
			ft_putstr_color(buf, GREEN);
		else if (i % 3 == 0)
			ft_putstr_color(buf, YELLOW);
		else
			ft_putstr_color(buf, RED);
		if (!ft_strchr(opts, 'l') && !ft_strchr(opts, '1'))
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

	if (*paths)
	{
		buff = l_sort(paths);
		if (ft_strchr(opts, 't') != NULL)
			buff = t_sort(buff);
		if (ft_strchr(opts, 'r') != NULL)
			buff = r_sort(buff);
		if (ft_strchr(opts, 'l') != NULL)
			buff = opt_l(buff);
		printer(buff, opts);
		if (!ft_strchr(opts, 'l') && !ft_strchr(opts, '1'))
			ft_putchar('\n');
	}
}

static int	add_path(char ***p, char ***ret, char *opts, char *path)
{
	t_dir	d;
	char	*buf;

	if ((d.dirp = opendir(path)) == NULL || !is_allowed(path))
		return (fd_error(path));
	while ((d.dp = readdir(d.dirp)) != NULL)
	{
		if (!ft_strchr(opts, 'a') && (d.dp->d_name)[0] == '.')
			continue;
		buf = extend(path, d.dp->d_name);
		if ((ft_strchr(opts, 'l') || ft_strchr(opts, 'R')) && !is_allowed(buf))
		{
			fd_error(buf);
			free(buf);
			continue ;
		}
		ft_addstr(p, buf);
		if (is_dir(buf) && ft_strchr(opts, 'R') != NULL &&
				ft_strcmp(d.dp->d_name, ".") && ft_strcmp(d.dp->d_name, ".."))
			ft_addstr(ret, buf);
		free(buf);
	}
	(void)closedir(d.dirp);
	return (1);
}

static char	**show_dir(char *path, char *opts)
{
	char			**paths;
	char			**ret;
	t_max			max;

	paths = (char **)malloc(sizeof(char*));
	*paths = NULL;
	ret = (char **)malloc(sizeof(char*));
	*ret = NULL;
	if (ft_strchr(opts, 'l') && is_slink(path))
	{
		ft_addstr(&paths, path);
		max = get_max(paths);
		ft_addstr(&ret, stat_path(path, max));
		print_all(paths, opts);
		return (NULL);
	}
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

	i = -1;
	if (count++ == 0)
		print_all(extract_files(startdirs, &count), opts);
	while (startdirs[++i])
	{
		if (startdirs[i][0] != '-')
		{
			if (count > 1 || (count == 1 && startdirs[1] != NULL))
			{
				count > 1 ? ft_putchar('\n') : ft_strlen("XD");
				ft_putstr(ft_strjoin(startdirs[i], ":\n"));
			}
			if ((buf = l_sort(show_dir(startdirs[i], opts))) != NULL)
			{
				buf = ft_strchr(opts, 't') != NULL ? t_sort(buf) : buf;
				buf = ft_strchr(opts, 'r') != NULL ? r_sort(buf) : buf;
				recursive(buf, opts);
			}
		}
	}
	return (EXIT_SUCCESS);
}
