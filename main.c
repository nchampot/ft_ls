#include "ft_ls.h"

static void show_me(char **t, int is_longformat)
{
    int i;
    
    i = 0;
    while (t[i])
    {
        ft_putstr(t[i]);
        if (!is_longformat)
            ft_putchar('\n');
        else if (t[i +1])
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
    if  (ft_strchr(opts, 'R'))
        recursive(&print, startdirs, !ft_strchr(opts, 'a'));
    else if ((print = init(startdirs, !ft_strchr(opts, 'a'))) == NULL)
        {
            ft_putstr_fd("WRONG DIRECTORY\n", 2);
            return (1);
        }
	//longformat(ac, av, &print);
	//lex_sort(ac, av, &print);
	//time_sort(ac, av, &print);
	//reverse_sort(ac, av, &print);
    show_me(print, !ft_strchr(opts, 'l'));

	return (1);
}
