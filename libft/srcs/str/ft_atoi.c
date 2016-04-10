#include "libft.h"

/*
** The `ft_atoi()` function converts the initial portion of the string `str`
** to `int` representation.
** The string may begin with an arbitrary amount of white space, followed by
** a single, optional, '+' or '-' sign.
*/
int		ft_atoi(const char *str)
{
	int		number;
	char	scalar;

	number = 0;
	scalar = 1;
	while (*str != '\0' && ft_isspace((unsigned char)*str))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			scalar = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit((unsigned char)*str))
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (scalar * number);
}
