/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctypes3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:14:52 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:14:54 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctypes.h"

int	ft_isspace(int c)
{
	return (g_ctype_arr[(c)] & _DT_SPACE);
}

int	ft_isupper(int c)
{
	return (g_ctype_arr[(c)] & _DT_UPPER);
}

int	ft_isxdigit(int c)
{
	return (g_ctype_arr[(c)] & _DT_XDIGIT);
}

int	ft_toascii(int c)
{
	return ((c) & 0x7F);
}
