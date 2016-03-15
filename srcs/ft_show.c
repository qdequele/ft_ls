/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:57:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_debug_t_opt(t_opt opt)
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

void	ft_show_name(t_list *node)
{
	t_elem *elem;

	elem = node->content;
	if (elem->err)
	{
		ft_putstr(elem->err);
		ft_putstr("\n");
	}
	else
	{
		if (elem->type == 'd')
			ft_putstr_c(CYAN, elem->name);
		else
			ft_putstr(elem->name);
		ft_putstr("\n");
	}
}
void	ft_show_detailled_name(void const *wc, t_list *node)
{
	t_elem	*elem;
	t_width	*w;

	w = (t_width *)wc;
	elem = node->content;
	printf("%c%s  %s %s  %s  %s %s %s\n", 
		elem->type,
		ft_get_right(elem->stat.st_mode),
		ft_float_right_text(w->nb_nlink, ft_itoa((int)elem->stat.st_nlink)),
		ft_get_name(elem->stat.st_uid),
		ft_get_group(elem->stat.st_gid),
		ft_float_right_text(w->nb_size, ft_itoa((int)elem->stat.st_size)),
		ft_get_time(elem->stat.st_mtime),
		elem->name);
}