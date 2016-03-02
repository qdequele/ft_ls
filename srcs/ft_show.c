/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 18:21:32 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_debug_t_opt(t_opt opt)
{
    ft_putstr("\n#######ft_debug_t_opt########\n");
    ft_putstr("options passed : ");
    if (opt.l == 1)
        ft_putchar('l');
    if (opt.R == 1)
        ft_putchar('R');
    if (opt.a == 1)
        ft_putchar('a');
    if (opt.r == 1)
        ft_putchar('r');
    if (opt.t == 1)
        ft_putchar('t');
    ft_putstr("\n#######END########\n");
}
void    ft_debug_files(t_file file)
{
    ft_putstr("\n#######ft_debug_files########\n");
    ft_putstr("file->name : ");
    ft_putstr(file.name);
    ft_putstr("file->path : ");
    ft_putstr(file.path);
    ft_putstr("\n#######END########\n");
}
