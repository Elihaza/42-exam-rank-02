/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <ellarbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:30:14 by ellarbi           #+#    #+#             */
/*   Updated: 2022/01/12 13:32:17 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup(char *str) {
    int i = 0;
    char *new;
    while (str[i])
        i++;
    new = malloc(i + 1);
    i = 0;
    while (str[i]) {
        new[i] = str[i];
        i++;
    }
    new[i] = 0;
    return (new);
}

char *get_next_line2(int fd) {
    int i = 0;
    int r = 1;
    char c;
    char line[8000000] = {};
    while ((r = read(fd, &c, 1)) > 0) {
        line[i++] = c;
        if (c == '\n')
            break;
    }
    if (line[0] == 0)
        return (NULL);
    return (ft_strdup(line));
}