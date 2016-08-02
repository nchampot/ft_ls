/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:57:12 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/20 13:24:53 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		count;

	count = 0;
	count += ft_putstr_fd(s, fd);
	count += ft_putchar_fd('\n', fd);
	return (count);
}

int		ft_putendl(char const *s)
{
	return (ft_putendl_fd(s, STDOUT_FILENO));
}

int		ft_putendl_color(char const *s, char *color)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putendl("\x1B[0m");
	return (0);
}

int		ft_putstr_color(char const *s, char *color)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr("\x1B[0m");
	return (0);
}
