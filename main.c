#include "ft_ls.h"

static void show_me(char **t, int is_longformat)
{
	int i;

	i = 0;
	while (t[i])
	{
		ft_putstr(t[i]);
		if ( is_longformat && t[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int main(int ac, char **av)
{
	char	**print;
	char	**startdirs;
	char	*opts;

	print = (char**)malloc(sizeof(char*));
	*print = NULL;
	startdirs = (char**)malloc(sizeof(char*));
	opts = malloc(1);
	*opts = '\0';
	*startdirs = NULL;
	parse_args(ac, av, &startdirs, &opts);
	recursive(&print, startdirs, opts);
	//longformat(ac, av, &print);
	//lex_sort(ac, av, &print);
	//time_sort(ac, av, &print);
	//reverse_sort(ac, av, &print);
	show_me(print, !ft_strchr(opts, 'l'));
	return (1);
}
