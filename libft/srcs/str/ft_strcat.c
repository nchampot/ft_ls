/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:38 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:06:49 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The `ft_strcat()` function appends the string `s2` to the string `s1`.
** `s1` must have sufficient space to hold both strings.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s1_begin;

	s1_begin = s1;
	while (*s1)
		s1++;
	while ((*s1++ = *s2++))
		;
	return (s1_begin);
}
