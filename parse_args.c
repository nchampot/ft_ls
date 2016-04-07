/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghassem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:58:16 by pghassem          #+#    #+#             */
/*   Updated: 2016/04/07 19:19:34 by pghassem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_opt(char c)
{
	return ((c == 'a') || (c == 'R') || (c == 'l') || (c == 't') || (c == 'r'));
}

int			parse_args(int ac, char **av, char ***startdirs, char **opts)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (**startdirs == '\0' && av[i][0] == '-')
			parse(i, 1, av, opts);
		else if (av[i][0] != '-')
			ft_addstr(startdirs, av[i]);
		i++;
	}
	if (**startdirs == '\0')
		ft_addstr(startdirs, ".");
	return (1);
}

int			parse(int i, int j, char **av, char **opts)
{
	while (av[i][j])
	{
		if (is_opt(av[i][j]))
		{
			if (!ft_strchr(*opts, av[i][j]))
				ft_addchr(opts, av[i][j]);
		}
		else
			return ((int)av[i][j]);
		j++;
	}
	return (1);
}
