/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 12:09:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    ft_get_type_of(struct stat stat)
{
    if (S_ISBLK(stat.st_mode) == 1)
        return ('b');
    if (S_ISCHR(stat.st_mode) == 1)
        return ('c');
    if (S_ISDIR(stat.st_mode) == 1)
        return ('d');
    if (S_ISFIFO(stat.st_mode) == 1)
        return ('f');
    if (S_ISREG(stat.st_mode) == 1)
        return ('-');
    if (S_ISLNK(stat.st_mode) == 1)
        return ('l');
}
