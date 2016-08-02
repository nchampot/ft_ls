/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:40:09 by edelbe            #+#    #+#             */
/*   Updated: 2016/08/02 14:59:16 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_file(char *name)
{
	t_dir	d;

	if ((d.dirp = opendir(".")) == NULL)
		return (0);
	while ((d.dp = readdir(d.dirp)) != NULL)
		if (ft_strcmp(name, d.dp->d_name) == 0)
			return (1);
	return (0);
}

char		**extract_files(char **startdirs, int *count)
{
	int		i;
	char	**buf;
	int		x;

	buf = (char **)malloc(sizeof(char*));
	*buf = NULL;
	i = 0;
	x = 0;
	while (startdirs[i])
	{
		if (startdirs[i][0] == '-')
		{
			x++;
			ft_addstr(&buf, (startdirs[i]) + 1);
		}
		i++;
	}
	if (x != 0)
		(*count)++;
	return (buf);
}

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
