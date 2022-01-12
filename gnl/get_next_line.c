/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <ellarbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:25:05 by ellarbi           #+#    #+#             */
/*   Updated: 2022/01/12 13:32:33 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line) {
    int i = -1; // for loop line 30
    int l = 1; // line length for malloc
    int r = 0; // return value for get_next_line
    char c; // char for read on fd 0
    char *tmp; // tmp for malloc and buffer

    if (!(*line = malloc(l)))
        return -1;
    (*line)[0] = 0;
    while ((r = read(0, &c, 1) && l++ && c != '\n')) {
        if (!(tmp = malloc(l))) {
            free(*line);
            return -1;
        }
        while (++i < l - 2)
            tmp[i] = (*line)[i];
        tmp[i] = c;
        tmp[i + 1] = 0;
        free(*line);
        *line = tmp;
    }
    return r;
}