/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:56:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:11:53 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** The `ft_putchar_fd()` function writes the character `c` (converted to an
** unsigned char) to the file descriptor `fd`.
*/

int		ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	return (write(fd, &chr, 1));
}

int		ft_putchar(char c)
{
	return (ft_putchar_fd(c, STDOUT_FILENO));
}
