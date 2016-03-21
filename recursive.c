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
	struct stat	filestat;
	struct group	*filegroup;

	i = 0;
	while (to_print[i])
	{
		buf = ft_strdup(ft_strrchr(to_print[i], '/') + 1);
		if (!ft_strchr(opts, 'a') && (buf)[0] == '.')
		{
			i++;
			free(buf);
			continue;
		}
		if (ft_strchr(opts, 'l') != NULL)
		{
			opt_l(to_print[i], filestat, filegroup);
			ft_putchar('\n');
		}
		else
		{
		ft_putstr(buf);
			ft_putchar(' ');
		}
		i++;
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
		if ((buf = show_dir(startdirs[i], opts)) != NULL)
		{
			count++;
			recursive(buf, opts);
			free(buf);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
