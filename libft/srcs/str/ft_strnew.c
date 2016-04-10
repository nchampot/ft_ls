#include <string.h>
#include "libft.h"

/*
** The `ft_strnew()` function creates a new string of `size` characters, fills
** it with '\0's, and returns a pointer to the freshly-allocated memory.
*/
char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(size + 1));
}
