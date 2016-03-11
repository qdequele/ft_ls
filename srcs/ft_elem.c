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

t_elem	*ft_create_elem(char *str)
{
	t_elem	*new_elem;

	if (!(new_elem = malloc(sizeof(t_elem))))
		ft_memory_error();
	if (!(new_elem->path = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		ft_memory_error();
	new_elem->path = str;
	new_elem->next = NULL;
	if (lstat(str, &new_elem->stat) == -1)
		new_elem->err = ft_not_found_concat(str);
	else
		new_elem->type = ft_get_type_of(new_elem->stat);
	return (new_elem);
}

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
