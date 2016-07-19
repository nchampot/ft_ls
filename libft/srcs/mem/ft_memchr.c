/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:13:40 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:13:44 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The `ft_memchr()` function locates the first occurrence of `c` (converted
** to an unsigned char) in string `s`, searching only the first `n` bytes.
** The function returns a pointer to the byte located, or NULL otherwise.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*p_s = s;

	while (n--)
	{
		if (*p_s == (unsigned char)c)
			return ((void*)p_s);
		p_s++;
	}
	return (NULL);
}
