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

void	ft_show_name(t_list *node)
{
	t_elem *elem;

	elem = node->content;
	if (elem->err)
	{
		// ft_printendl(elem->err, 'e');
		return ;
	}
	else if (elem->name && elem->type)
	{
		ft_printendl(elem->name, elem->type);
	}
}

void	ft_show_path(t_env *env, t_elem *elem)
{
	if (g_options.lines != 0)
	{
		ft_putstr("\n");
	}
	if (g_options.args > 1 && env->has_files == 0)
		env->first++;
	if ((ft_strcmp(elem->path, ".") && g_options.R && g_options.args == 0))
	{
		ft_print("./", 'p');
		ft_print(elem->path, 'p');
		ft_print(":\n", 'p');
	}
	else if (g_options.args >= 1 && (env->first != 0 || env->has_files != 0))
	{
		ft_print(elem->path, 'p');
		ft_print(":\n", 'p');
	}
	env->first++;
}

void	ft_show_files(t_list *node)
{
	t_width	*w;

	w = ft_get_width_list(node);
	if (!g_options.l)
		ft_iter(node, ft_show_name);
	else if (node->content && ((t_elem *)node->content)->name)
	{
		ft_putstr("total ");
		ft_putnbr(w->total);
		ft_putchar('\n');
		ft_iter_plus(node, (void const *)w, ft_show_detailled_name);
	}
}
