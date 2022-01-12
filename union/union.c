/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <ellarbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:17:24 by ellarbi           #+#    #+#             */
/*   Updated: 2022/01/12 13:19:24 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

void ft_union(char *str, int *tab) {
    int i = 0;
    while (str[i]) {
        if (tab[(unsigned char)str[i]] == 0) {
            ft_putchar(str[i]);
            tab[(unsigned char)str[i]] = 1;
        }
        i++;
    }
}

int main(int ac, char **av) {
    int tab[256] = {};
    if (ac == 3) {
        ft_union(av[1], tab);
        ft_union(av[2], tab);
    }
    ft_putchar('\n');
    return 0;
}