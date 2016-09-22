/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:10:03 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/22 08:32:01 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define NOPE 0
#define YEP 1

static int	*init_order(int len)
{
	int	*order;
	int	i;

	order = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		order[i] = i;
		i++;
	}
	return (order);
}

static int	get_len(char **paths)
{
	int	len;

	len = 0;
	while (paths[len])
		len++;
	return (len++);
}

static int	*bubble_sort(char **paths)
{
	int		*order;
	int		i;
	int		is_sorted;
	int		tmp;
	int		len;

	len = get_len(paths);
	is_sorted = NOPE;
	order = init_order(len);
	while (is_sorted == NOPE && len--)
	{
		is_sorted = YEP;
		i = -1;
		while (i++ < (len - 1))
		{
			if (ft_strcmp(paths[order[i]], paths[order[i + 1]]) > 0)
			{
				tmp = order[i];
				order[i] = order[i + 1];
				order[i + 1] = tmp;
				is_sorted = NOPE;
			}
		}
	}
	return (order);
}

char		**l_sort(char **paths)
{
	char	**new;
	int		i;
	int		*order;

	if (paths == NULL)
		return (NULL);
	order = bubble_sort(paths);
	new = (char**)malloc(sizeof(char*));
	*new = NULL;
	i = 0;
	while (paths[i])
	{
		ft_addstr(&new, paths[order[i]]);
		i++;
	}
	return (new);
}

char		**r_sort(char **paths)
{
	int		i;
	char	**tab;

	if (paths == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*));
	*tab = NULL;
	i = 0;
	while (paths[i])
		i++;
	while (i--)
		ft_addstr(&tab, paths[i]);
	return (tab);
}
