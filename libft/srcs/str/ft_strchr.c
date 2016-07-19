/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:43 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:06:55 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_strchr()` function locates the 1st occurence of `c` (converted to a
** char) in `s`; if `c` is '\0', the function will locate this terminating '\0'.
** The function returns a pointer to the located character, or NULL otherwise).
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char*)s);
}
