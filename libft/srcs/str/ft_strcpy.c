/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:57 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:07:11 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The `ft_strcpy()` copies string `s2` to `s1` (including the terminating '\0'
** character). The source and destination strings should not overlap, as the
** behavior is undefined.
*/

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*s1_begin;

	s1_begin = s1;
	while ((*s1++ = *s2++))
		;
	return (s1_begin);
}
