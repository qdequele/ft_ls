/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:57:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_show_detailled_name(void const *wc, t_list *node)
{
	t_elem	*elem;
	t_width	*w;

	w = (t_width *)wc;
	elem = node->content;
	ft_print_c(elem->type, elem->type);
	ft_print(ft_get_right(elem->stat.st_mode), elem->type);
	ft_print("  ", elem->type);
	ft_print(ft_float_right_text(w->nlink, ft_itoa((int)elem->stat.st_nlink)), elem->type);
	ft_print(" ", elem->type);
	ft_show_uid_gid(w, elem);
	ft_print("  ", elem->type);
	ft_show_size(w, elem);
	ft_print(" ", elem->type);
	ft_show_date(elem);
	ft_print(" ", elem->type);
	ft_print(elem->name, elem->type);
	ft_print("\n", elem->type);
}

void	ft_show_uid_gid(t_width *w, t_elem	*elem)
{
	char	*user;
	char	*group;

	user = ft_get_user(elem->stat.st_uid);
	group = ft_get_group(elem->stat.st_gid);
	if (!user)
		user = ft_itoa(elem->stat.st_uid);
	if (!group)
		group = ft_itoa(elem->stat.st_gid);
	ft_print(ft_float_left_text(w->uid, user), elem->type);
	ft_print("  ", elem->type);
	ft_print(ft_float_left_text(w->gid, group), elem->type);
}

void	ft_show_size(t_width *w, t_elem	*elem)
{
	char	*size;
	char	*major;
	char	*minor;

	if (elem->type == 'c' || elem->type == 'b')
	{
		major = ft_itoa(major((int)elem->stat.st_rdev));
		minor = ft_itoa(minor((int)elem->stat.st_rdev));
		if (w->size_format && w->mm_format)
			ft_print(ft_float_right_text((w->sm - w->minor), major), elem->type);
		else
			ft_print(ft_float_right_text(w->major, major), elem->type);
		ft_print(", ", elem->type);
		ft_print(ft_float_right_text(w->minor, minor), elem->type);
	}
	else
	{
		size = ft_itoa((int)elem->stat.st_size);
		if (w->size_format && w->mm_format)
			ft_print(ft_float_right_text(w->sm, size), elem->type);
		else
			ft_print(ft_float_right_text(w->size, size), elem->type);
	}
}

void	ft_show_date(t_elem	*elem)
{
	char	*time;

	time = ft_get_time(elem->stat.st_mtime);
	ft_print(time, elem->type);
}