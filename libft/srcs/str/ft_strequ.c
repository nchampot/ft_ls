#include "libft.h"

/*
** The `ft_strequ()` function lexicographically compares null-terminated string
** `s1` with null-terminated string `s2`. If the strings are equal, the function
** returns 1; if the strings are different, the function returns 0.
*/
int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (!ft_strcmp(s1, s2))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
