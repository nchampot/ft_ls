/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 08:20:56 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 13:23:20 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_stuff(char **stuff)
{
	int		i;

	i = -1;
	while (stuff[++i])
		free(stuff[i]);
	free(stuff);
}
