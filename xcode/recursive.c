//
//  recursive.c
//  ft_ls
//
//  Created by Noe Champot on 2/17/16.
//  Copyright © 2016 Noe Champot. All rights reserved.
//

#include "ft_ls.h"



static int    rekt(char ***print, char *curr)
{
    DIR  *dirp;
    struct dirent   *dp;
    int i;
    
    i = 0;
    if ((dirp = opendir(curr)) == NULL)
        return (EXIT_FAILURE);
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_type == DT_DIR && (dp->d_name)[0] != '.')
        {
            add_str(print, ft_strjoin("\n\n/", ft_strjoin(ft_strjoin(curr, "/"), ft_strjoin(dp->d_name, ":\n"))));
             if (curr[ft_strlen(curr) - 1] != '/')
                rekt(print, ft_strjoin(ft_strjoin(curr, "/"), dp->d_name));
            else
                rekt(print, ft_strjoin(curr, dp->d_name));
        }
        else
            add_str(print, dp->d_name);
    }
    (void)closedir(dirp);
    return (EXIT_SUCCESS);
}

static int    rektt(char ***print, char *curr)
{
    DIR  *dirp;
    struct dirent   *dp;
    int i;
    
    i = 0;
    if ((dirp = opendir(curr)) == NULL)
        return (EXIT_FAILURE);
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_type == DT_DIR && (dp->d_name)[0] != '.' && (dp->d_name)[1])
        {
            add_str(print, ft_strjoin("\n\n/", ft_strjoin(ft_strjoin(curr, "/"), ft_strjoin(dp->d_name, ":\n"))));
             if (curr[ft_strlen(curr) - 1] != '/')
                rektt(print, ft_strjoin(ft_strjoin(curr, "/"), dp->d_name));
            else
                rektt(print, ft_strjoin(curr, dp->d_name));
        }
        else if ((dp->d_name)[0] != '.')
            add_str(print, dp->d_name);
    }
    (void)closedir(dirp);
    return (EXIT_SUCCESS);
}

int    recursive(char ***print, char **startdirs, int is_all)
{
    int i;
    
    i = 0;
    while (startdirs[i])
    {
        if (is_all)
        {
            if (!rektt(print, startdirs[i]))
                return (EXIT_FAILURE);
        }
        else
        {
            if (!rekt(print, startdirs[i]))
                return (EXIT_FAILURE);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}