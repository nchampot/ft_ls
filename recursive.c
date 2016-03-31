//
//  recursive.c
//  ft_ls
//
//  Created by Noe Champot on 2/17/16.
//  Copyright © 2016 Noe Champot. All rights reserved.
//

#include "ft_ls.h"

static void	print_all(char **to_print, char *opts)
{
	int	i;
	char	*buf;
	char	**buff;

	buff = lex_sort(to_print);
	if (ft_strchr(opts, 't') != NULL)
		buff = t_sort(buff);
	if (ft_strchr(opts, 'r') != NULL)
		buff = r_sort(buff);
	if (ft_strchr(opts, 'l') != NULL)
		buff = opt_l(buff);
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
	if (!ft_strchr(opts, 'l'))
		ft_putchar('\n');
}

static char	**show_dir(char *path, char *opts)
{
	DIR  *dirp;
	struct dirent   *dp;
	int i;
	char	**to_print;
	char	**ret_dirs;

	i = 0;
	if ((dirp = opendir(path)) == NULL)
		return (NULL);
	to_print = (char **)malloc(sizeof(char*));
	*to_print = NULL;
	if (ft_strchr(opts, 'R') != NULL)
	{
		ret_dirs = (char **)malloc(sizeof(char*));
		*ret_dirs = NULL;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!ft_strchr(opts, 'a') && (dp->d_name)[0] == '.')
			continue;
		if (path[ft_strlen(path) - 1] != '/')
		{
			ft_addstr(&to_print, ft_strjoin(ft_strjoin(path, "/"), dp->d_name));
			if (dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
				ft_addstr(&ret_dirs, ft_strjoin(ft_strjoin(path, "/"), dp->d_name));
		}
		else
		{
			ft_addstr(&to_print, ft_strjoin(path, dp->d_name));
			if (dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
				ft_addstr(&ret_dirs, ft_strjoin(path, dp->d_name));
		}
	}
	(void)closedir(dirp);
	print_all(to_print, opts);
	return (ret_dirs);
}

int    recursive(char **startdirs, char *opts)
{
	int i;
	char	**buf;
	static int count = 0;

	i = 0;
	while (startdirs[i])
	{
		if (count > 0)
		{
			ft_putchar('\n');
			ft_putstr(startdirs[i]);
			ft_putstr(":\n");
		}
		if ((buf = lex_sort(show_dir(startdirs[i], opts))) != NULL)
		{
			if (ft_strchr(opts, 't') != NULL)
				buf = t_sort(buf);
			if (ft_strchr(opts, 'r') != NULL)
				buf = r_sort(buf);
			count++;
			recursive(buf, opts);
			free(buf);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
