#include <string.h>

/*
** The `ft_strncpy()` function copies at most `n` characters from null-
** terminated string `s1` to null-terminated string `s2`, and then returns s1.
** If copy ends but `s1` still has space, it gets filled with '\0's.
** The end copy is not guaranteed to be null-terminated!
*/
char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		++i;
	}
	while (i < n)
		s1[i++] = '\0';
	return (s1);
}
