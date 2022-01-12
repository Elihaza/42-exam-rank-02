/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <ellarbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:13:03 by ellarbi           #+#    #+#             */
/*   Updated: 2022/01/12 13:15:34 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

int ft_check(char c, char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

void ft_inter(char *s1, char *s2, int *tab) {
    int i = 0;
    while (s1[i]) {
        if (tab[(unsigned char)s1[i]] == 0 && ft_check(s1[i], s2)) {
            ft_putchar(s1[i]);
            tab[(unsigned char)s1[i]] = 1;
        }
        i++;
    }
}

int main(int ac, char **av) {
    int tab[256] = {};
    if (ac == 3)
        ft_inter(av[1], av[2], tab);
    ft_putchar('\n');
    return 0;
}