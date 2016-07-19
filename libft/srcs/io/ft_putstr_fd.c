/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:12:27 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:12:39 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"

/*
** The `ft_putstr()` function writes the null-terminated string `s` to the
** file descriptor `fd`.
*/

int		ft_putstr_fd(char const *s, int fd)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	return (write(fd, s, len_s));
}

int		ft_putstr(char const *s)
{
	return (ft_putstr_fd(s, STDOUT_FILENO));
}
