/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:28:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 13:28:24 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	recursive(char **startdirs, char *opts)
{
	int			i;
	char		**buf;
	static int	count = 0;

	i = -1;
	if (count++ == 0)
		print_all(extract_files(startdirs, &count), opts);
	while (startdirs[++i])
	{
		if (startdirs[i][0] != '-')
		{
			if (count > 1 || (count == 1 && startdirs[1] != NULL))
			{
				count > 1 ? ft_putchar('\n') : ft_strlen("XD");
				ft_putstr(ft_strjoin(startdirs[i], ":\n"));
			}
			if ((buf = get_next_dirs(startdirs[i], opts)) != NULL)
			{
				recursive(buf, opts);
				free_stuff(buf);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	char	**startdirs;
	char	*opts;

	startdirs = (char**)malloc(sizeof(char*));
	opts = ft_strnew(0);
	*startdirs = NULL;
	if (parse_args(ac, av, &startdirs, &opts) != 1)
		return (EXIT_FAILURE);
	else
		recursive(startdirs, opts);
	return (EXIT_SUCCESS);
}
