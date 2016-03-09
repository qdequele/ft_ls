/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_push_elem(t_env *env, t_elem *elem)
{
	t_elem	*tmp_elem;
	tmp_elem = env->elems;

	if (!elem)
		return ;
	if (env->elems == NULL)
	{
		env->elems = elem;
	}
	else
	{
		while (tmp_elem->next)
		{
			tmp_elem = tmp_elem->next;
		}
		tmp_elem->next = elem;
	}
}

void	ft_elem_for_each(t_env *env, void (*function)(t_elem *elem))
{
	t_elem	*tmp_elem;
	tmp_elem = env->elems;

	if (!tmp_elem)
		return ;
	else
	{
		while (tmp_elem->next)
		{
			function(tmp_elem);
			tmp_elem = tmp_elem->next;
		}
		function(tmp_elem);
	}
}