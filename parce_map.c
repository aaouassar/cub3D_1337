/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:57:02 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 12:29:55 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/get_next_line.h"

int   first_check(char *str, int *x)
{
    while (*str == ' ' || *str == '\t' ||*str == '\n' )
        str++;
    if(!*str)
        return (2);
    else if (!ft_strncmp(str, "NO", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "SO", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "WE", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "EA", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "F", 1))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "C", 1))
    {
        (*x)++;
        return (0);
    }
    else
    {
        printf("ERROR nono\n");
        exit(1);
    }
}
void    seconde_check(char *str, int i, int len)
{
    char *path;

    while(str[i] == ' ' || str[i] == '\t')
        i++;
    i += 2;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    path = ft_substr(str, i, len - i);
    // printf("-------------%s\n", path);
    // int fdd = open(path, O_RDONLY);
    // if (fdd == -1)
    // {
    //     printf("error path\n");
    //     exit(1);
    // }
}