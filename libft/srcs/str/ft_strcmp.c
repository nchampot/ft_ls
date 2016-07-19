/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:53 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:07:06 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_strcmp()` function lexicographically compare strings `s1` and `s2`.
** The function returns 0 if the strings are identical; otherwise, it returns
** the difference in ASCII value between the first differing characters.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char *)s2);
}
