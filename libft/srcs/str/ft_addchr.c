/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:07 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:11:14 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_addchr(char **pstring, const char c)
{
	char	*new;
	int		i;

	i = ft_strlen(*pstring);
	new = ft_strnew(i + 1);
	ft_strcat(new, *pstring);
	new[i] = c;
	*pstring = new;
	return (*pstring);
}
