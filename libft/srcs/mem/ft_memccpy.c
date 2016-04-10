#include <string.h>

/*
** The `ft_memccpy()` function copies bytes from string `s2` to string `s1`.
** If the character `c` (as converted to an unsigned char) occurs in `s2`,
** the copy stops and a pointer to the byte after the copy of `c` in the
** string `s1` is returned. Otherwise, `n` bytes are copied, and function
** returns NULL.
*/
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*p_s1;
	const char		*p_s2 = s2;

	p_s1 = s1;
	while (n--)
	{
		*p_s1++ = *p_s2;
		if (*p_s2 == (unsigned char)c)
			return (p_s1);
		p_s2++;
	}
	return (0);
}
