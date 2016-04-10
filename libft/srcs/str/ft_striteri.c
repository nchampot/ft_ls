#include <string.h>

/*
** The `ft_striteri()` function applies function `void f(unsigned int, char *)`
** to each character of the null-terminated string `s`.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
