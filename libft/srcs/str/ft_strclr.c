/*
** The `ft_strclr()` function assigns '\0' to every character of the `s` string.
*/
void	ft_strclr(char *s)
{
	while (*s)
		*s++ = '\0';
}
