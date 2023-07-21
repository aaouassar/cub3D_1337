/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:20:48 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 14:39:04 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/get_next_line.h"

//int x = 0;

// void    seconde_check(char *str, int fd, int i, int len)
// {
//     (void)fd;
//     char *path;

//     while(str[i] == ' ' || str[i] == '\t')
//         i++;
//     i += 2;
//     while(str[i] == ' ' || str[i] == '\t')
//         i++;
//     path = ft_substr(str, i, len - i);
//     printf("-------------%s\n", path);
//     // int fdd = open(path, O_RDONLY);
//     // if (fdd == -1)
//     // {
//     //     printf("error path\n");
//     //     exit(1);
//     // }
// }

// int   first_check(char *str, int *x)
// {
//     while (*str == ' ' || *str == '\t' ||*str == '\n' )
//     {
//         str++;
//     }
//     if(!*str)
//         return (2);
//     else if (!ft_strncmp(str, "NO", 2))
//     {
//         (*x)++;
//         return (0);
//     }
//     else if (!ft_strncmp(str, "SO", 2))
//     {
//         (*x)++;
//         return (0);
//     }
//     else if (!ft_strncmp(str, "WE", 2))
//     {
//         (*x)++;
//         return (0);
//     }
//     else if (!ft_strncmp(str, "EA", 2))
//     {
//         (*x)++;
//         return (0);
//     }
//     else if (!ft_strncmp(str, "F", 1))
//     {
//         (*x)++;
//         return (0);
//     }
//     else if (!ft_strncmp(str, "C", 1))
//     {
//         (*x)++;
//         return (0);
//     }
//     else
//     {
//         printf("ERROR nono\n");
//         exit(1);
//     }
// }

void     third_check(char *str)
{
    char **rgb;
    int f = 0;
    int c = 0;
    int flag = 0;

    while (*str == ' ' || *str == '\t')
        str++;
    if (str[0] == 'C')
        flag = 1;
    str++;
    while (*str == ' ' || *str == '\t')
        str++; 
    rgb = ft_split(str, ',');
    if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255) || (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255) || (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
    {
        printf("ERROR\n");
        exit(1);
    }
    if(!flag)
        f = (ft_atoi(rgb[0]) * 65536) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
    else if(flag)
        c = (ft_atoi(rgb[0]) * 65536) + (ft_atoi(rgb[1]) * 256) +  ft_atoi(rgb[2]);
}

int     ft_correct(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 32)
                return(0);
            j++;
        }    
        i++;
    }
    return(1);    
}

void     ft_valid(char **map)
{
    int i;
    int j;

    
    i = 1;
    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != ' ' && map[0][j] != '1')
        {
            printf("map not closed\n");
            exit(1);
        }
        j++;
    }
    while (map[i + 1])
    {
        if (map[i][j] == ' ')
        {
            if (map[i - 1][j] != '1' || map[i + 1][j] != '1'  || map[i][j - 1] != '1' || map[i][j + 1] != '1')
            {
                printf("map not closedkk\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != ' ' && map[i][j] != '1')
        {
            printf("map not closed\n");
            exit(1);
        }
        j++;
    }
}

void    ft_checknewline(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == '\n' && str[i + 1] == '\n')
        {
            printf("map not correct\n");
            exit(1);
        }
        i++;
    }   
}
void    parce_check(int fd)
{
    int i;
    int x;
    int len;
    char    *str;
    char *s;
    char **map;

    x = 0;
    i = 0;
    s = calloc(1, 1);
    while (1)
    {
        i = 0;
        str = get_next_line(fd);
        if (str == NULL)
                break;
        if(x < 6)
        {
            len = ft_strlen(str);
            while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                i++;
            if (str[i] == '\n')
                continue ;
            first_check(str, &x);
            if (x <= 4)
                seconde_check(str, i, len);
            if (x > 4)
                third_check(str);
        }
        else if (x >= 6)
            s = ft_strjoin(s ,str);
    }
    ft_checknewline(s);
    map = ft_split(s, '\n');
    if (ft_correct(map) == 0)
    {
        printf("invalid map\n");
        exit(1);
    }
    else 
        ft_valid(map);
}

void   ft_check(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
   if (i >= 4 && (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' || str[i - 3] != '.'))
   {
        printf("ERROR\n");
        exit(1);
   }
}


int main(int ac, char **av)
{
    int fd;

	if (ac > 2 || ac == 1)
		ft_putstr("you should pass just 2 argument");
	else if (ac == 2)
    {
        ft_check(av[1]);
        fd = open(av[1], O_RDONLY);
        parce_check(fd);
    }
}

