/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctypes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:14:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:14:49 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctypes.h"

int	ft_isdigit(int c)
{
	return (g_ctype_arr[(c)] & _DT_DIGIT);
}

int	ft_isgraph(int c)
{
	return (g_ctype_arr[(c)] & _DT_GRAPH);
}

int	ft_islower(int c)
{
	return (g_ctype_arr[(c)] & _DT_LOWER);
}

int	ft_isprint(int c)
{
	return (g_ctype_arr[(c)] & _DT_PRINT);
}

int	ft_ispunct(int c)
{
	return (g_ctype_arr[(c)] & _DT_PUNCT);
}
