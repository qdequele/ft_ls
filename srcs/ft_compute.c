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

	ft_select_sort((t_env *)ev, node);
	elem = node->content;
	if (elem->type == 'd')
	{
		ft_compute_dir(ev, node);
	}
	else
		ft_putendl(elem->name);
}

void	ft_compute_dir(const void *ev, t_list *node)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	t_list			*sub_lst;
	t_elem			*elem;

	sub_lst = NULL;
	pDir = NULL;
	ft_select_sort((t_env *)ev, node);
	elem = node->content;
	if (elem->type == 'd')
	{
		ft_show_path((t_env *)ev, elem);
		if ((pDir = opendir (elem->path)) == NULL)
			ft_not_found_exit(elem->path);
		while ((pDirent = readdir(pDir)) != NULL) {
			ft_lstaddend(&sub_lst, ft_lstnew(ft_create_elem(pDirent->d_name, elem->path), sizeof(t_elem)));
		}
		closedir (pDir);
		ft_select_sort((t_env *)ev, sub_lst);
		ft_show_files((t_env *)ev, sub_lst);
		if (((t_env *)ev)->opt.R)
			ft_lstiter_if_plus(sub_lst, ev, ft_compute_dir, reject_dot_folder);
	}
}


void	ft_select_sort(t_env *env, t_list *node)
{
	if (env->opt.t)
		ft_lst_bubble_sort(node, ft_sort_by_modification_time);
	else
		ft_lst_bubble_sort(node, ft_sort_by_lexycography);
	if (env->opt.r)
		ft_sort_reverse(node);
}

void	ft_show_path(t_env *env, t_elem *elem)
{
	if (env->opt.args != 1)
		ft_putstr("\n");
	if ((strcmp(elem->path, ".") && env->opt.R && env->opt.args == 0))
	{
		ft_putstr("./");
		ft_putstr(elem->path);
		ft_putstr(":\n");
	}
	else if(strcmp(elem->path, ".") && env->opt.args > 1)
	{
		ft_putstr(elem->path);
		ft_putstr(":\n");
	}
}

void	ft_show_files(t_env *env, t_list *node)
{
	if (env->opt.a)
		ft_lstiter(node, ft_show_name);
	else
		ft_lstiter_if(node, ft_show_name, reject_dot_folder);
}