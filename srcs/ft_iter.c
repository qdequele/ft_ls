/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_iter(t_list *node, void (*f)(t_list *elem))
{
	if (g_options.a)
		ft_lstiter(node, f);
	else
		ft_lstiter_if(node, f, reject_dot_folder);
}

void	ft_iter_plus(t_list *node, void const *param,
	void (*f)(void const *info, t_list *elem))
{
	if (g_options.a)
		ft_lstiter_plus(node, param, f);
	else
		ft_lstiter_if_plus(node, param, f, reject_dot_folder);
}
