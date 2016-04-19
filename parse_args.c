/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghassem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:58:16 by pghassem          #+#    #+#             */
/*   Updated: 2016/04/11 15:49:07 by edelbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_opt(char c)
{
	return ((c == 'a') || (c == 'R') || (c == 'l') || (c == 't') || (c == 'r'));
}

static int	is_dir(char *dir)
{
	DIR	*dirp;
	
	if ((dirp = opendir(dir)) == NULL)
		return (fd_error(dir));
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
		else if (av[i][0] != '-' && is_dir(av[i]))
			ft_addstr(startdirs, av[i]);
		i++;
	}
	if (**startdirs == '\0')
		ft_addstr(startdirs, ".");
	return (1);
}
