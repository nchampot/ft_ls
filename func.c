#include "ft_ls.h"

void	add_spaces(char	**buf, int nb_space)
{
	int	i;

	i = 0;
	while (i < nb_space)
	{
		ft_addchr(buf, ' ');
		i++;
	}
}

int	nb_digit(int nb)
{
	int	count;
	int	buf;

	count = 1;
	buf = nb;
	while (buf > 9)
	{
		buf = buf / 10;
		count++;
	}
	return (count);
}

t_max	init_max(void)
{
	t_max	max;

	max.st_size = 0;
	max.nlink = 0;
	max.len_pwname = 0;
	max.len_grname = 0;
	return (max);
}
