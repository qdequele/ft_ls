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

void	ft_open_dir(const void *ev, t_list *node)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	t_elem			*elem;
	t_list			*lst;
	t_env			*env;

	env = (t_env *)ev;
	elem = node->content;
	lst = NULL;
	//ft_debug_elems(node);
	pDir = NULL;
	if (elem->type == 'd')
	{
		if (strcmp(elem->path, "."))
		{
			ft_putstr("\n./");
			ft_putstr(elem->path);
			ft_putstr(":\n");
		}
		pDir = opendir (elem->path);
		if (pDir == NULL) {
			ft_not_found_exit(elem->path);
		}
		while ((pDirent = readdir(pDir)) != NULL) {
			ft_lstaddend(&lst, ft_lstnew(ft_create_elem(pDirent->d_name, elem->path), sizeof(t_elem)));
		}
		ft_lst_bubble_sort(lst, ft_sort_by_lexycography);
		if (env->opt.R)
				ft_lstiter_if_plus(lst, ev, ft_open_dir, reject_dot_folder);
		if (env->opt.a)
			ft_lstiter(lst, ft_show_name);
		else
			ft_lstiter_if(lst, ft_show_name, reject_dot_folder);

		closedir (pDir);
	}
	else
	{
		ft_putstr(elem->name);
		ft_putstr("\n");
	}
}