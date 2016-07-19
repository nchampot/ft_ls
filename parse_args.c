/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghassem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:58:16 by pghassem          #+#    #+#             */
/*   Updated: 2016/07/19 13:20:42 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_opt(char c)
{
	return ((c == 'a') || (c == 'R') || (c == 'l') || (c == 't') || (c == 'r'));
}

static int	check_dir(char *dir, char ***fails)
{
	DIR	*dirp;

	if ((dirp = opendir(dir)) == NULL)
	{
		ft_addstr(fails, dir);
		return (0);
	}
	(void)closedir(dirp);
	return (1);
}

static int	check_opts(char *s, char **opts)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if (is_opt(s[i]))
		{
			if (!ft_strchr(*opts, s[i]))
				ft_addchr(opts, s[i]);
		}
		else
		{
			ft_putstr_fd("usage: ft_ls: illegal option -- ", 2);
			ft_putchar_fd(s[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putendl_fd(USAGE, 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_args(char **av, char ***startdirs, char **opts, char ***fails)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (**startdirs == '\0' && av[i][0] == '-')
		{
			if (!check_opts(av[i], opts))
				return (0);
		}
		else if (av[i][0] != '-')
		{
			if (check_dir(av[i], fails))
				ft_addstr(startdirs, av[i]);
		}
		i++;
	}
	return (1);
}

int			parse_args(int ac, char **av, char ***startdirs, char **opts)
{
	int		i;
	char	**buf;
	char	**fails;

	fails = (char**)malloc(sizeof(char*));
	*fails = NULL;
	if (check_args(av, startdirs, opts, &fails))
	{
		buf = l_sort(fails);
		i = 0;
		while (buf[i])
			fd_error(buf[i++]);
	}
	else
		return (-1);
	if (**startdirs == '\0')
	{
		if (*buf)
			return (-1);
		else
			ft_addstr(startdirs, ".");
	}
	else
		*startdirs = l_sort(*startdirs);
	return (1);
}
