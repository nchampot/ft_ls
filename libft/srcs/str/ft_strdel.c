/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:59:01 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:07:16 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The `ft_strdel()` function frees the memory used by the `as` string, then
** sets the pointer to NULL. This function does nothing if `as` is null.
*/

void	ft_strdel(char **as)
{
	if (*as)
		ft_memdel((void**)as);
}
