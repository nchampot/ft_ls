#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <dirent.h>
#include "libft/inc/libft.h"


int parse_args(int ac, char **av, char ***startdirs, char **opts);
char    **init(char **startdirs, int is_all);
int    recursive(char ***print, char **startdirs, char *opts);

#endif
