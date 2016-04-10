#include <string.h>

/*
** The `ft_strcpy()` copies string `s2` to `s1` (including the terminating '\0'
** character). The source and destination strings should not overlap, as the
** behavior is undefined.
*/
char	*ft_strcpy(char *s1, const char *s2)
{
	char	*s1_begin;

	s1_begin = s1;
	while ((*s1++ = *s2++))
		;
	return (s1_begin);
}
