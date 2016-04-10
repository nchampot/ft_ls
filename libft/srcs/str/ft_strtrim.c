#include <string.h>
#include "libft.h"

/*
** The `ft_strtrim()` function trims the leading and trailing whitespaces of
** the null-terminated string `s`, creates a new, fresh string out of the
** trimmed result, and returns a pointer to it. The function returns NULL if
** memory allocation fails.
*/
char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*new_str;

	while (*s && ft_isspace((unsigned char)*s))
		s++;
	len = ft_strlen(s);
	while (*s && ft_isspace((unsigned char)s[--len]))
		;
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	new_str = ft_strncpy(new_str, s, len + 1);
	new_str[len + 1] = '\0';
	return (new_str);
}
