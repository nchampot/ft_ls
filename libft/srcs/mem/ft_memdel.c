#include <stdlib.h>

/*
** The `ft_memdel()` function frees the memory used by the `ap` pointer, then
** sets the pointer to NULL. This function does nothing if pointer is NULL.
*/
void	ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
