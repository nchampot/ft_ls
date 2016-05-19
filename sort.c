/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:54:45 by nchampot          #+#    #+#             */
/*   Updated: 2016/04/11 15:50:46 by edelbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_dots(char **paths, char ***tab)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (ft_strcmp(ft_strrchr(paths[i], '/') + 1, ".") == 0 ||
			ft_strcmp(ft_strrchr(paths[i], '/') + 1, "..") == 0)
			ft_addstr(tab, paths[i]);
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (ft_strcmp(ft_strrchr(paths[i], '/') + 1, ".") == 0||
			ft_strcmp(ft_strrchr(paths[i], '/') + 1, "..") == 0)
		{
			i++;
			continue;
		}
		else if ((ft_strrchr(paths[i], '/'))[1] == '.' &&
			ft_isupper((ft_strrchr(paths[i], '/'))[2]))
			ft_addstr(tab, paths[i]);
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (ft_strcmp(ft_strrchr(paths[i], '/') + 1, ".") == 0||
			ft_strcmp(ft_strrchr(paths[i], '/') + 1, "..") == 0)
		{
			i++;
			continue;
		}
		else if ((ft_strrchr(paths[i], '/'))[1] == '.' &&
			ft_isupper((ft_strrchr(paths[i], '/'))[2]))
		{
			i++;
			continue;
		}
		else if ((ft_strrchr(paths[i], '/'))[1] == '.' &&
			!ft_isupper((ft_strrchr(paths[i], '/'))[2]))
			ft_addstr(tab, paths[i]);
		i++;
	}
}

static void	add_uppercases(char **paths, char ***tab)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (ft_isupper((ft_strrchr(paths[i], '/'))[1])
				&& (ft_strrchr(paths[i], '/'))[1] != '.')
			ft_addstr(tab, paths[i]);
		i++;
	}
}

static void	add_rest(char **paths, char ***tab)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (!ft_isupper((ft_strrchr(paths[i], '/'))[1])
				&& (ft_strrchr(paths[i], '/'))[1] != '.')
			ft_addstr(tab, paths[i]);
		i++;
	}
}

char		**lex_sort(char **paths)
{
	char	**tab;
	char	**buff;

	if (paths == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*));
	*tab = NULL;
	if (paths[0] && ft_strlen(paths[0]) > 3 && ft_strcmp(ft_strsub(paths[0], 0, 4), "/dev") == 0)
		buff = l_sort(paths);
	else
		buff = paths;
	add_dots(buff, &tab);
	add_uppercases(buff, &tab);
	add_rest(buff, &tab);
	return (tab);
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
