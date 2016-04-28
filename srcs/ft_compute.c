/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_compute_dir_option_r(t_list *sub_lst, const void *ev)
{
	if (g_options.R)
	{
		if (g_options.a)
			ft_lstiter_if_plus(sub_lst, ev, ft_compute_dir, reject_dot);
		else
			ft_lstiter_if_plus(sub_lst, ev, ft_compute_dir, reject_dot_folder);
	}
}

static void	ft_show_name_option_l(t_list *node)
{
	if (g_options.l)
		ft_show_detailled_name(ft_get_width_list(node), node);
	else
		ft_show_name(node);
}

static DIR	*ft_compute_dir_opendir(t_list *node, t_elem *elem)
{
	DIR		*pdir;

	pdir = NULL;
	if (elem->type == 'l')
	{
		if ((pdir = opendir(ft_get_linked_name(elem))) == NULL)
		{
			ft_show_name_option_l(node);
			return (NULL);
		}
		return (pdir);
	}
	else
	{
		if ((pdir = opendir(elem->path)) == NULL)
		{
			ft_not_found_exit(elem->path);
			return (NULL);
		}
		return (pdir);
	}
}

void		ft_compute_dir(const void *ev, t_list *node)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	t_list			*sub_lst;
	t_elem			*elem;

	elem = node->content;
	if (elem->type == 'd')
	{
		sub_lst = NULL;
		ft_show_path((t_env *)ev, elem);
		pdir = ft_compute_dir_opendir(node, elem);
		if (pdir)
		{
			while ((pdirent = readdir(pdir)) != NULL)
				ft_lstaddend(&sub_lst, ft_lstnew(ft_create_elem(pdirent->d_name,
					elem->path), sizeof(t_elem)));
			closedir(pdir);
			ft_select_sort((t_env *)ev, &sub_lst);
			ft_show_files(sub_lst);
			ft_compute_dir_option_r(sub_lst, ev);
		}
	}
}

void		ft_compute(const void *ev, t_list *node)
{
	t_elem			*elem;

	ft_select_sort((t_env *)ev, &node);
	elem = node->content;
	if (elem->type == 'd')
		ft_compute_dir(ev, node);
	else
	{
		if (!elem->err || ft_strlen(elem->err) != 0)
			if (g_options.l)
				ft_show_detailled_name(ft_get_width_list(node), node);
			else
				ft_show_name(node);
		else
			ft_show_files(node);
	}
}
