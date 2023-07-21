/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:21:00 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 12:50:42 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

typedef struct  s_rgb
{
    int floor;
    int ceilin;
} t_rgb ;

int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const	char *s);
void	ft_putstr(char *s);
void   ft_check(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);


int   first_check(char *str, int *x);
void    seconde_check(char *str, int i, int len);


#endif