#include "libft.h"
#include <stdlib.h>

char	*ft_addchr(char **pString, const char c)
{
	char	*new;
	int	i;

	i = ft_strlen(*pString);
	new = ft_strnew(i + 1); 
	ft_strcat(new, *pString);
	new[i] = c;
	*pString = new;
	return (*pString);
}
