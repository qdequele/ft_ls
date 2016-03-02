/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_not_found_exit(char *str)
{
    ft_putstr("ls: ");
    ft_putstr(str);
    ft_putstr(": No such file or directory\n");
    exit(0);
}

void    ft_illegal_option_exit(char *str)
{
    ft_putstr("ls: illegal option -- ");
    ft_putstr(str);
    ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
    exit(0);
}
