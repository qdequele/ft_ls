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
		ft_printendl(elem->err, 'e');
	}
	else
	{
		ft_printendl(elem->name, elem->type);
	}
}

void	ft_show_path(t_env *env, t_elem *elem)
{
	if (env->first != 0)
		ft_putstr("\n");
	if ((strcmp(elem->path, ".") && g_options.R && g_options.args == 0))
	{
		ft_print("./", 'p');
		ft_print(elem->path, 'p');
		ft_print(":\n", 'p');
	}
	else if(g_options.args >= 1 && env->first != 0)
	{
		ft_print(elem->path, 'p');
		ft_print(":\n", 'p');
	}
	env->first++;
}