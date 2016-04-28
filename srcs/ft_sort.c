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
	t_elem	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (n_elem && ft_strcmp(elem->name, n_elem->name) > 0)
		return (1);
	return (0);
}

int		ft_sort_by_lexycography_folder_end(t_list *node)
{
	t_elem	*elem;
	t_elem	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (!elem || !n_elem)
		return (0);
	if (elem->type != 'd' && n_elem->type == 'd')
		return (0);
	if ((ft_strcmp(elem->name, n_elem->name) > 0)
		|| (elem->type == 'd' && n_elem->type != 'd'))
		return (1);
	return (0);
}

int		ft_sort_by_lexycography_folder_end_r(t_list *node)
{
	t_elem	*elem;
	t_elem	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (!elem || !n_elem)
		return (0);
	if (elem->type != 'd' && n_elem->type == 'd')
		return (0);
	if ((ft_strcmp(elem->name, n_elem->name) < 0)
		|| (elem->type == 'd' && n_elem->type != 'd'))
		return (1);
	return (0);
}

int		ft_sort_by_modification_time(t_list *node)
{
	t_elem	*elem;
	t_elem	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (!elem || !n_elem)
		return (0);
	return (ft_get_max_time(elem, n_elem));
}

int		ft_sort_reverse(t_list **node)
{
	*node = ft_lst_reverse(*node);
	return (1);
}
