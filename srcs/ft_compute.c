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
		ft_show_name(node);
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
		while ((pDirent = readdir(pDir)) != NULL) {
			ft_lstaddend(&sub_lst, ft_lstnew(ft_create_elem(pDirent->d_name, elem->path), sizeof(t_elem)));
		}
		ft_select_sort((t_env *)ev, &sub_lst);
		ft_show_files((t_env *)ev, sub_lst);
		if (((t_env *)ev)->opt.R)
			ft_lstiter_if_plus(sub_lst, ev, ft_compute_dir, reject_dot_folder);
		closedir (pDir);
	}
}

void	ft_select_sort(t_env *env, t_list **node)
{
	if (env->opt.t)
		ft_lst_bubble_sort(*node, ft_sort_by_modification_time);
	else
	{
		if (env->has_files != 0 && env->first == 0)
		{
			if (env->opt.r)
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
	if (env->opt.r)
		ft_sort_reverse(node);
}

void	ft_show_path(t_env *env, t_elem *elem)
{
	if (env->first++ != 0)
		ft_putstr("\n");
	if ((strcmp(elem->path, ".") && env->opt.R && env->opt.args == 0))
	{
		ft_putstr_c(YELLOW, "./");
		ft_putstr_c(YELLOW, elem->path);
		ft_putstr_c(YELLOW, ":\n");
	}
	else if(strcmp(elem->path, ".") && env->opt.args > 1)
	{
		ft_putstr_c(YELLOW, elem->path);
		ft_putstr_c(YELLOW, ":\n");
	}
}

void	ft_show_files(t_env *env, t_list *node)
{
	if (env->opt.a)
		ft_lstiter(node, ft_show_name);
	else
		ft_lstiter_if(node, ft_show_name, reject_dot_folder);
}