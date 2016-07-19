/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:14:00 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:14:03 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The `ft_memmove()` safely copies `n` bytes from `s2` to `s1`.
** Behavior of `p_s2 < p_s1` is undefined if these variables do not point
** within the same object. Use the `restrict` keyword (not portable) in C99.
*/

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*p_s1;
	const unsigned char	*p_s2 = s2;

	if (!n)
		return (s1);
	p_s1 = s1;
	if (p_s2 < p_s1)
	{
		p_s1 += n;
		p_s2 += n;
		while (n--)
			*--p_s1 = *--p_s2;
	}
	else
	{
		while (n--)
			*p_s1++ = *p_s2++;
	}
	return (s1);
}
