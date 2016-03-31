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
# define NOPE 0
# define YEP 1

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

static int	cmpdates(char *path1, char *path2)
{
	struct stat	filestat1;
	struct stat	filestat2;

	if (lstat(path1, &filestat1) < 0)
		exit(0);
	if (lstat(path2, &filestat2) < 0)
		exit(0);
	return(difftime(filestat1.st_mtimespec.tv_sec, filestat2.st_mtimespec.tv_sec));
}

char	**t_sort(char **paths)
{
	int	*order;
	char	**new;
	int	i;
	int	j;
	int	is_sorted;
	int	tmp;
	int	len;

	i = 0;
	len = 0;
	is_sorted = NOPE;
	new = (char**)malloc(sizeof(char*));
	*new = NULL;
	while (paths[len])
		len++;
	order = malloc(sizeof(int) * len);
	while (i < len)
	{
		order[i] = i;
		i++;
	}
	i = 0;
	while (i < len && is_sorted == NOPE)
	{
		is_sorted = YEP;
		j = 1;
		while (j < (len - i))
		{
			if (cmpdates(paths[order[j - 1]], paths[order[j]]) < 0)
			{
				tmp = order[j - 1];
				order[j - 1] = order[j];
				order[j] = tmp;
				is_sorted = NOPE;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		ft_addstr(&new, paths[order[i]]);
		i++;
	}
	return (new);
}
