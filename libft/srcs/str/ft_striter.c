/*
** The `ft_striter()` function applies function `f` (pointer) to each character
** of the null-terminated string `s`.
*/
void	ft_striter(char *s, void (*f)(char*))
{
	while (*s)
		f(s++);
}
