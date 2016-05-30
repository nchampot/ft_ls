/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 18:43:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/05/30 13:46:51 by nchampot         ###   ########.fr       */
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

	buff = l_sort(paths);
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


static int	add_path(char ***p, char ***ret, char *opts, char *path)
{
	t_dir	d;
	char	*buf;

	if ((d.dirp = opendir(path)) == NULL)
		return (fd_error(path));
	while ((d.dp = readdir(d.dirp)) != NULL)
	{
		if (!ft_strchr(opts, 'a') && (d.dp->d_name)[0] == '.')
			continue;
		buf = extend(path, d.dp->d_name);
		ft_addstr(p, buf);
		if (is_dir(buf) && ft_strchr(opts, 'R') != NULL
				&& ft_strcmp(d.dp->d_name, ".") && ft_strcmp(d.dp->d_name, ".."))
			ft_addstr(ret, buf);
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
		if ((buf = l_sort(show_dir(startdirs[i], opts))) != NULL)
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
