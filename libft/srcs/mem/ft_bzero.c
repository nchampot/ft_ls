/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:13:12 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:13:28 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** The `ft_bzero()` function writes `n` zeroed bytes to string `so.
** If `n` is zero, `ft_bzero()` does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	if (n)
		ft_memset((unsigned char*)s, 0, n);
}
