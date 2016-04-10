#include "libft.h"

/*
** The `ft_strdel()` function frees the memory used by the `as` string, then
** sets the pointer to NULL. This function does nothing if `as` is null.
*/
void	ft_strdel(char **as)
{
	if (*as)
		ft_memdel((void**)as);
}
