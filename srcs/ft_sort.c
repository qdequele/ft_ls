/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sort_by_lexycography(t_list *node)
{
	t_elem	*elem;
	t_elem	*next;

	elem = node->content;
	next = node->next->content;
	if (next && strcmp(elem->name, next->name) > 0)
		return (1);
	return (0);
}
//-t
int		ft_sort_by_modification_time(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (elem->next && elem->stat.st_mtime < elem->next->stat.st_mtime)
		return (1);
	return (0);
}
//-r
int		ft_sort_reverse(t_list *node)
{
	node = ft_lst_reverse(node);
	return (1);
}