/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:34:35 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/19 09:20:37 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<limits.h>
# include<fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_line(char *stach);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen1(char *str);
char	*get_next(int fd, char *stach);
char	*ft_rest(char *rst);
char	*free_it(char *c);
#endif
