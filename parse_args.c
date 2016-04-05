#include "ft_ls.h"

static int	is_opt(char c)
{
	return ((c == 'a') || (c =='R') || (c == 'l') || (c == 't') || (c == 'r'));
}

int	parse_args(int ac, char **av, char ***startdirs, char **opts)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (**startdirs == '\0' && av[i][0] == '-')
		{
			j = 1;
			while (av[i][j])
			{
				if (is_opt(av[i][j]))
				{
					if (!ft_strchr(*opts, av[i][j]))
						ft_addchr(opts, av[i][j]);
				}
				else
				{
					ft_putstr_fd("ls: illegal option -- ", 2);
					ft_putchar_fd(av[i][j], 2);
					ft_putchar_fd('\n', 2);
					return (-1);
				}
				j++;
			} 
		}
		else if (av[i][0] != '-')
			ft_addstr(startdirs, av[i]);
		i++;
	}
	if (**startdirs == '\0')
			ft_addstr(startdirs, ".");
	return (1);
}
