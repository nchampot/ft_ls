/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:59:57 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:08:53 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_strrchr()` function locates the last occurence of character `c`
** in string `s`.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*found_at;

	found_at = 0;
	while (*s)
	{
		if (*s == (char)c)
			found_at = (char*)s;
		s++;
	}
	found_at = (*s == (char)c) ? (char*)s : found_at;
	return (found_at);
}
