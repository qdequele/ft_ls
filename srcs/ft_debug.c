/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:57:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_debug_t_opt()
{
	ft_putstr("\n#######ft_debug_t_opt########\n");
	ft_putstr("g_options passed : ");
	if (g_options.l == 1)
		ft_putchar('l');
	if (g_options.R == 1)
		ft_putchar('R');
	if (g_options.a == 1)
		ft_putchar('a');
	if (g_options.r == 1)
		ft_putchar('r');
	if (g_options.t == 1)
		ft_putchar('t');
	ft_putstr("\n#######END########\n");
}

void	ft_debug_elems(t_list *node)
{
	t_elem *elem;

	elem = node->content;
	ft_putstr("\n#######ft_debug_elems########");
	ft_putstr("\nelem->name : ");
	if (elem->name)
		ft_putstr(elem->name);
	ft_putstr("\nelem->path : ");
	if (elem->path)
		ft_putstr(elem->path);
	ft_putstr("\nelem->err : ");
	if (elem->err) 
		ft_putstr(elem->err);
	ft_putstr("\nelem->type : ");
	ft_putchar(elem->type);
	ft_putstr("\n#######END########\n");
}