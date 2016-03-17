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

void	ft_compute(const void *ev, t_list *node)
{
	t_elem			*elem;

	ft_select_sort((t_env *)ev, &node);
	elem = node->content;
	if (elem->type == 'd')
	{
		ft_compute_dir(ev, node);
	}
	else
	{
		((t_env *)ev)->first++;
		ft_show_files(node);
	}
}

void	ft_compute_dir(const void *ev, t_list *node)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	t_list			*sub_lst;
	t_elem			*elem;

	elem = node->content;
	if (elem->type == 'd')
	{
		sub_lst = NULL;
		pDir = NULL;
		ft_show_path((t_env *)ev, elem);
		if ((pDir = opendir (elem->path)) == NULL)
			ft_not_found_exit(elem->path);
		while ((pDirent = readdir(pDir)) != NULL)
		{
			ft_lstaddend(&sub_lst, ft_lstnew(ft_create_elem(pDirent->d_name, elem->path), sizeof(t_elem)));
		}
		if (pDir)
			closedir (pDir);
		ft_select_sort((t_env *)ev, &sub_lst);
		ft_show_files(sub_lst);
		if (g_options.R)
			ft_lstiter_if_plus(sub_lst, ev, ft_compute_dir, reject_dot_folder);
	}
}

void	ft_select_sort(t_env *env, t_list **node)
{
	if (g_options.t)
		ft_lst_bubble_sort(*node, ft_sort_by_modification_time);
	else
	{
		if (env->has_files != 0 && env->first == 0)
		{
			if (g_options.r)
			{
				ft_lst_bubble_sort(*node, ft_sort_by_lexycography_folder_end_r);
				return ;
			}
			else
			{
				ft_lst_bubble_sort(*node, ft_sort_by_lexycography_folder_end);
			}
		}
		else
			ft_lst_bubble_sort(*node, ft_sort_by_lexycography);
	}
	if (g_options.r)
		ft_sort_reverse(node);
}

void	ft_show_files(t_list *node)
{
	t_width	*w;

	w = (t_width *)malloc(sizeof(t_width));
	ft_init_width(w);
	ft_iter_plus(node, (void const *)w, ft_get_max_width);
	if (!g_options.l)
		ft_iter(node, ft_show_name);
	else
	{
		ft_putstr("total ");
		ft_putnbr(w->total);
		ft_putchar('\n');
		ft_iter_plus(node, (void const *)w, ft_show_detailled_name);
	}
}