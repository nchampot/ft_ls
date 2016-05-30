/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghassem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:58:16 by pghassem          #+#    #+#             */
/*   Updated: 2016/05/30 13:54:36 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_opt(char c)
{
	return ((c == 'a') || (c == 'R') || (c == 'l') || (c == 't') || (c == 'r'));
}

static int	check_dir(char *dir)
{
	DIR	*dirp;
	
	if ((dirp = opendir(dir)) == NULL)
	{
		(void)closedir(dirp);
		return (fd_error(dir));
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
			return ((int)s[i]);
		i++;
	}
	return (1);
}

int			parse_args(int ac, char **av, char ***startdirs, char **opts)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (**startdirs == '\0' && av[i][0] == '-')
		{
			if (check_opts(av[i], opts) != 1)
				return (-1);
		}
		else if (av[i][0] != '-' && check_dir(av[i]))
			ft_addstr(startdirs, av[i]);
		i++;
	}
	if (**startdirs == '\0')
		ft_addstr(startdirs, ".");
	return (1);
}
