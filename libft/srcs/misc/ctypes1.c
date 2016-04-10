#include "libft_ctypes.h"

int	ft_isalnum(int c)
{
	return (g_ctype_arr[(c)] & (_DT_ALPHA | _DT_DIGIT));
}

int	ft_isalpha(int c)
{
	return (g_ctype_arr[(c)] & _DT_ALPHA);
}

int	ft_isascii(int c)
{
	return (((c) & ~0x7F) == 0);
}

int	ft_isblank(int c)
{
	return (g_ctype_arr[(c)] & _DT_BLANK);
}

int	ft_iscntrl(int c)
{
	return (g_ctype_arr[(c)] & _DT_CNTRL);
}
