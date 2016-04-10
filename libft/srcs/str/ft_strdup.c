#include <stdlib.h>
#include "libft.h"

/*
** The `ft_strdup()` function allocates sufficient memory for a copy of the
** string `s1`, does the copy, and returns a pointer to it.
** If insufficient memory is available, the function returns NULL.
*/
char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p != NULL)
		ft_strcpy(p, s1);
	return (p);
}
