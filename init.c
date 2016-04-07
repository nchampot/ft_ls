/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:26:15 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/07 16:28:32 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**init(char **startdirs, int is_all)
{
	char			**print;
	int				i;
	DIR				*dirp;
	struct dirent	*dp;

	print = (char**)malloc(sizeof(char*));
	*print = NULL;
	i = 0;
	while (startdirs[i])
	{
		dirp = opendir(startdirs[i]);
		if (dirp == NULL)
			return (NULL);
		while ((dp = readdir(dirp)) != NULL)
			if (!is_all || (dp->d_name)[0] != '.')
				ft_addstr(&print, dp->d_name);
		(void)closedir(dirp);
		i++;
	}
	return (print);
}
