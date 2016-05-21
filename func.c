/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:40:09 by edelbe            #+#    #+#             */
/*   Updated: 2016/05/21 19:24:02 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_spaces(char **buf, int nb_space)
{
	int		i;

	i = 0;
	while (i < nb_space)
	{
		ft_addchr(buf, ' ');
		i++;
	}
}

int			nb_digit(int nb)
{
	int		count;
	int		buf;

	count = 1;
	buf = nb;
	while (buf > 9)
	{
		buf = buf / 10;
		count++;
	}
	return (count);
}

t_max		init_max(void)
{
	t_max	max;

	max.st_size = 0;
	max.nlink = 0;
	max.len_pwname = 0;
	max.len_grname = 0;
	max.min_size = 0;
	max.maj_size = 0;
	return (max);
}
