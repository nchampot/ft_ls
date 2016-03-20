//
//  init.c
//  ft_ls
//
//  Created by Noe Champot on 2/17/16.
//  Copyright © 2016 Noe Champot. All rights reserved.
//

#include "ft_ls.h"

char    **init(char **startdirs, int is_all)
{
    char    **print;
    int i;
    DIR *dirp;
    struct dirent *dp;

    print = (char**)malloc(sizeof(char*));
    *print = NULL;
    i = 0;
    while (startdirs[i])
    {
        dirp = opendir(startdirs[i]);
        if (dirp == NULL)
            return (NULL);
        while ((dp = readdir(dirp)) != NULL)
            if (!is_all || (dp->d_name)[0] != '.')
                ft_addstr(&print, dp->d_name);
        (void)closedir(dirp);
        i++;
    }
    return (print);
}
