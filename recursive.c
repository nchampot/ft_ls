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

	i = 1;
	while (to_print[i])
	{
		ft_putstr(to_print[i]);
		ft_putchar(' ');
		i++;
	}
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
	if (ft_strchr(opts, 'R') != NULL)
	{
		ret_dirs = (char **)malloc(sizeof(char*));
		*ret_dirs = NULL;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
				ft_putnbr(dp->d_type);
				ft_putstr(dp->d_name);
				ft_putchar('\n');
		if (path[ft_strlen(path) - 1] != '/')
		{
			ft_addstr(&to_print, ft_strjoin(ft_strjoin(path, "/"), dp->d_name));
			if (dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
			{
				ft_putstr("test1\n");
				ft_addstr(&ret_dirs, ft_strjoin(ft_strjoin(path, "/"), dp->d_name));
			}
		}
		else
		{
			ft_addstr(&to_print, ft_strjoin(path, dp->d_name));
			if (dp->d_type == DT_DIR && ft_strchr(opts, 'R') != NULL && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
			{
				ft_putstr("test2\n");
				ft_addstr(&ret_dirs, ft_strjoin(path, dp->d_name));
			}
		}
	}
	(void)closedir(dirp);
	print_all(ret_dirs, opts);
	return (ret_dirs);
}

int    recursive(char **startdirs, char *opts)
{
	int i;
	char	**buf;

	i = 0;
	while (startdirs[i])
	{
		if ((buf = show_dir(startdirs[i], opts)) != NULL)
		{
			recursive(buf, opts);
			free(buf);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
