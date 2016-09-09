/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:28:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/09 04:48:26 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
