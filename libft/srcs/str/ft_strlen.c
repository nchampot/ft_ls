#include <string.h>

/*
** The `ft_strlen()` function gives the size of the null-terminated string `s`.
** The terminating '\0' character is not part of the calculation.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
