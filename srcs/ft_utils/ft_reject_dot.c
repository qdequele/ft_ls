/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reject_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		reject_dot_folder(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (ft_strncmp(elem->name, ".", 1) == 0)
		return (0);
	return (1);
}

int		reject_dot(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (ft_strcmp(elem->name, ".") == 0 || ft_strcmp(elem->name, "..") == 0)
		return (0);
	return (1);
}
