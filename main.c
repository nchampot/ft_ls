#include "ft_ls.h"

int main(int ac, char **av)
{
	char	**startdirs;
	char	*opts;

	startdirs = (char**)malloc(sizeof(char*));
	opts = malloc(1);
	*opts = '\0';
	*startdirs = NULL;
	parse_args(ac, av, &startdirs, &opts);
	recursive(startdirs, opts);
	return (1);
}
