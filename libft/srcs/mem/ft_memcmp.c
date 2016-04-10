#include <string.h>

/*
** The `ft_memcmp()` function compares byte string `s1` against byte
** string `s2`. Both strings are assumed to be `n` bytes long.
** The function returns the difference in value between the first two differing
** bytes (treated as unsigned char values), if any. Zero-length strings are ok.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*p_s1 = s1;
	const unsigned char		*p_s2 = s2;

	while (n--)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		else
		{
			p_s1++;
			p_s2++;
		}
	}
	return (0);
}
