#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "libft/inc/libft.h"


int		parse_args(int ac, char **av, char ***startdirs, char **opts);
int		recursive(char **startdirs, char *opts);
char	**opt_l(char **paths);

#endif
