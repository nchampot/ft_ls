/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:54:45 by nchampot          #+#    #+#             */
/*   Updated: 2016/03/30 02:30:03 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_upper(char c)
{
	return (c >= 65 && c <= 90);
}

char		**lex_sort(char **to_print)
{
	int	i;
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
		if (is_upper((ft_strrchr(to_print[i], '/'))[1]) && (ft_strrchr(to_print[i], '/'))[1] != '.')
			ft_addstr(&tab, to_print[i]);
		i++;
	}
	i = 0;
	while (to_print[i])
	{
		if (!is_upper((ft_strrchr(to_print[i], '/'))[1]) && (ft_strrchr(to_print[i], '/'))[1] != '.')
			ft_addstr(&tab, to_print[i]);
		i++;
	}
	return (tab);
}

char		**r_sort(char **to_print)
{
	int	i;
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

char	**t_sort(char **to_print)
{
	
}
