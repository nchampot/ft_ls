#include <unistd.h>

/*
** The `ft_putchar_fd()` function writes the character `c` (converted to an
** unsigned char) to the file descriptor `fd`.
*/
int		ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	return (write(fd, &chr, 1));
}

int		ft_putchar(char c)
{
	return (ft_putchar_fd(c, STDOUT_FILENO));
}
