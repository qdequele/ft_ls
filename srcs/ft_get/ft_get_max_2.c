/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_max_size(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen((int)stat.st_size) > w->size)
		w->size = ft_nbrlen((int)stat.st_size);
}

void	ft_get_max_sm(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen((int)stat.st_size) > w->sm)
		w->sm = ft_nbrlen((int)stat.st_size);
	if ((size_t)ft_nbrlen(major((int)stat.st_rdev)) +
		(size_t)ft_nbrlen(major((int)stat.st_rdev)) + 2 > w->sm)
		w->sm = (size_t)ft_nbrlen(major((int)stat.st_rdev)) +
				(size_t)ft_nbrlen(major((int)stat.st_rdev)) + 2;
}

void	ft_get_max_width(void const *st, t_list *node)
{
	t_elem	*elem;
	t_width	*w;

	elem = (t_elem *)node->content;
	w = (t_width *)st;
	if (elem->type == 'c' || elem->type == 'b')
		w->mm_format++;
	else
		w->size_format++;
	w->total += (int)elem->stat.st_blocks;
	ft_get_max_nlink(w, elem->stat);
	ft_get_max_uid(w, elem->stat);
	ft_get_max_gid(w, elem->stat);
	ft_get_max_major(w, elem->stat);
	ft_get_max_minor(w, elem->stat);
	ft_get_max_size(w, elem->stat);
	ft_get_max_sm(w, elem->stat);
}

t_width	*ft_get_width_list(t_list *node)
{
	t_width	*w;

	w = (t_width *)ft_memalloc(sizeof(t_width));
	ft_init_width(w);
	ft_iter_plus(node, (void const *)w, ft_get_max_width);
	return (w);
}
