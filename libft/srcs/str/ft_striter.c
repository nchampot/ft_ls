/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:59:13 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:07:30 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_striter()` function applies function `f` (pointer) to each character
** of the null-terminated string `s`.
*/

void	ft_striter(char *s, void (*f)(char*))
{
	while (*s)
		f(s++);
}
