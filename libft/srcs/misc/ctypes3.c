#include "libft_ctypes.h"

int	ft_isspace(int c)
{
	return (g_ctype_arr[(c)] & _DT_SPACE);
}

int	ft_isupper(int c)
{
	return (g_ctype_arr[(c)] & _DT_UPPER);
}

int	ft_isxdigit(int c)
{
	return (g_ctype_arr[(c)] & _DT_XDIGIT);
}

int	ft_toascii(int c)
{
	return ((c) & 0x7F);
}
