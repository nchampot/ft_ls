/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:54:45 by nchampot          #+#    #+#             */
/*   Updated: 2016/03/29 22:09:26 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	*lex_sort(char ***to_print)
{
	int	i;
	int	*tab;

	i = 0;
	while ((*to_print)[i])
	{
		j = 0;
		while ((*to_print)[i][j] == (*to_print)[i + 1][j])
			j++;
	}
}