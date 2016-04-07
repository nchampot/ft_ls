/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:54:45 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/07 17:56:20 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**lex_sort(char **to_print)
{
	int		i;
	char	**tab;

	if (to_print == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*));
	*tab = NULL;
	i = 0;
	while (to_print[i])
	{
		if ((ft_strrchr(to_print[i], '/'))[1] == '.')
			ft_addstr(&tab, to_print[i]);
		i++;
	}
	i = 0;
	while (to_print[i])
	{
		if (ft_isupper((ft_strrchr(to_print[i], '/'))[1]) && (ft_strrchr(to_print[i], '/'))[1] != '.')
			ft_addstr(&tab, to_print[i]);
		i++;
	}
	i = 0;
	while (to_print[i])
	{
		if (!ft_isupper((ft_strrchr(to_print[i], '/'))[1]) && (ft_strrchr(to_print[i], '/'))[1] != '.')
			ft_addstr(&tab, to_print[i]);
		i++;
	}
	return (tab);
}

char		**r_sort(char **to_print)
{
	int		i;
	char	**tab;

	if (to_print == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*));
	*tab = NULL;
	i = 0;
	while (to_print[i])
		i++;
	while (i--)
		ft_addstr(&tab, to_print[i]);
	return (tab);
}
