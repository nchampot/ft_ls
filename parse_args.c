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
        if (av[i][0] == '-' && av[i][0] != '/')
		{
			j = 1;
			while (av[i][j])
			{
				if (is_opt(av[i][j]) && !ft_strchr(*opts, av[i][j]))
					add_chr(opts, av[i][j]);
				else
					return (-1);
				j++;
			} 
		}
		else
			add_str(startdirs, av[i]);
		i++;
	}
    if (**startdirs == '\0')
        **startdirs = ft_strdup(".");
    return (1);
}

