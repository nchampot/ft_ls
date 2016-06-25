/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghassem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:58:16 by pghassem          #+#    #+#             */
/*   Updated: 2016/06/25 17:14:58 by nchampot         ###   ########.fr       */
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
			return (0);
		i++;
	}
	return (1);
}

int			parse_args(int ac, char **av, char ***startdirs, char **opts)
{
	int		i;
	int		count;
	char	**buf;
	char	**fails;

	fails = (char**)malloc(sizeof(char*));
	*fails = NULL;
	i = 1;
	count = 0;
	while (av[i])
	{
		if (**startdirs == '\0' && av[i][0] == '-')
			check_opts(av[i], opts);
		else if (av[i][0] != '-')
		{
		   	if (check_dir(av[i], &fails))
				ft_addstr(startdirs, av[i]);
			else
				count++;
		}
		i++;
	}
	i = 0;
	buf = l_sort(fails);
	while (buf[i])
		fd_error(buf[i++]);
	if (**startdirs == '\0')
	{
	   if (count == 0)
		   ft_addstr(startdirs, ".");
	   else if (!(*buf))
		   return (-1);
	}
	else
		*startdirs = l_sort(*startdirs);
	return (1);
}
