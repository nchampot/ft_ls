//
//  recursive.c
//  ft_ls
//
//  Created by Noe Champot on 2/17/16.
//  Copyright © 2016 Noe Champot. All rights reserved.
//

#include "ft_ls.h"

static char	*to_print(char *curr, char *opts, struct dirent *dp)
{
	char	*buf;

	if (!ft_strchr(opts, 'a') && dp->d_name[0] == '.')
		return (NULL);
	buf = ft_strdup(dp->d_name);
	if (!ft_strchr(opts, 'R') != '\0')
	{
		if (dp->d_type == DT_DIR)
		{
			buf = ft_strjoin("\n\n", ft_strjoin(ft_strjoin(curr, "/"), ft_strjoin(buf, ":\n")));
			return (buf);
		}
	}
	if (ft_strchr(opts, 'l') != '\0')
		buf = ft_strjoin(buf, " +stats\n");
	else
		buf = ft_strjoin(buf, " ");
	return (buf);
}

static int    rekt(char *curr, char *opts)
{
	DIR  *dirp;
	struct dirent   *dp;
	int i;
	char	**to_print;

	i = 0;
	if ((dirp = opendir(curr)) == NULL)
		return (EXIT_FAILURE);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_type == DT_DIR && ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, "..")
			&& !(!ft_strchr(opts, 'R')))
		{
			//ft_addstr(print, to_print(curr, opts, dp));
			if (to_print(curr, opts, dp) != NULL)
				ft_putstr(to_print(curr, opts, dp));
			if (curr[ft_strlen(curr) - 1] != '/')
				rekt(print, ft_strjoin(ft_strjoin(curr, "/"), dp->d_name), opts);
			else
				rekt(print, ft_strjoin(curr, dp->d_name), opts);
		}
		else if (to_print(curr, opts, dp) != NULL)
			ft_putstr(to_print(curr, opts, dp));
	}
	(void)closedir(dirp);
	return (EXIT_SUCCESS);
}

int    recursive(char ***print, char **startdirs, char *opts)
{
	int i;

	i = 0;
	while (startdirs[i])
	{
		if (!rekt(print, startdirs[i], opts))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
