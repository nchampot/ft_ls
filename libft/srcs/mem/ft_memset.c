#include <string.h>

/*
** The `ft_memset()` function writes `len` bytes of value `c` (converted to an
** unsigned char) to the byte string `b`. The function returns its 1st argument.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bstr;

	bstr = b;
	while (len--)
	{
		*bstr = (unsigned char)c;
		bstr++;
	}
	return (b);
}
