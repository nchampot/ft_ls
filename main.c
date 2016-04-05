#include "ft_ls.h"

int main(int ac, char **av)
{
	char	**startdirs;
	char	*opts;

	startdirs = (char**)malloc(sizeof(char*));
	opts = malloc(1);
	*opts = '\0';
	*startdirs = NULL;
	if (parse_args(ac, av, &startdirs, &opts) == -1)
	{
		ft_putendl_fd(USAGE, 2);
		return (-1);
	}
	else
		recursive(startdirs, opts);
	return (1);
}
