/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:28:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/05/30 11:06:06 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	char	**startdirs;
	char	*opts;

	startdirs = (char**)malloc(sizeof(char*));
	opts = malloc(1);
	*opts = '\0';
	*startdirs = NULL;
	if (parse_args(ac, av, &startdirs, &opts) != 1)
	{
		ft_putendl_fd(USAGE, 2);
		return (EXIT_FAILURE);
	}
	else
		recursive(startdirs, opts);
	return (EXIT_SUCCESS);
}
