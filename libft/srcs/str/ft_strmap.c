#include <string.h>
#include "libft.h"

/*
** The `ft_strmap()` function applies function `f(char))` to each character of
** the null-terminated string `s`; the function does not modify `s` directly;
** it creates a new string instead, and returns it.
*/
char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	while (len--)
		*(new_str + len) = f(*(s + len));
	return (new_str);
}
