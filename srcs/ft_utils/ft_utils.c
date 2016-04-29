/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_get_type_of(struct stat stat)
{
	if (S_ISBLK(stat.st_mode) == 1)
		return ('b');
	if (S_ISDIR(stat.st_mode) == 1)
		return ('d');
	if (S_ISFIFO(stat.st_mode) == 1)
		return ('f');
	if (S_ISREG(stat.st_mode) == 1)
		return ('-');
	if (S_ISLNK(stat.st_mode) == 1)
		return ('l');
	if (S_ISCHR(stat.st_mode) == 1)
		return ('c');
	if (S_ISSOCK(stat.st_mode) == 1)
		return ('s');
	else
		return ('e');
}

t_elem	*ft_create_elem(char *str, char *prev_path)
{
	t_elem	*new_elem;

	new_elem = ft_memalloc(sizeof(t_elem));
	new_elem->path = ft_memalloc(sizeof(char)
		* (ft_strlen(str) + ft_strlen(prev_path) + 1));
	if (ft_strcmp(prev_path, ".") == 0)
		new_elem->path = ft_strdup(str);
	else
	{
		if (ft_strlen(prev_path) > 0)
			prev_path = ft_strfjoin(ft_strdup(prev_path), "/");
		new_elem->path = ft_strfjoin(ft_strdup(prev_path), ft_strdup(str));
	}
	new_elem->name = ft_strdup(str);
	new_elem->err = 0;
	if (lstat(new_elem->path, &new_elem->stat) == -1)
	{
		new_elem->err = 1;
		ft_not_found_exit(str);
	}
	else
		new_elem->type = ft_get_type_of(new_elem->stat);
	if (g_options.l && new_elem->type == 'l')
		ft_concat_linked_name(new_elem);
	return (new_elem);
}

void	ft_select_sort(t_env *env, t_list **node)
{
	if (g_options.t)
		ft_lst_bubble_sort(*node, ft_sort_by_modification_time);
	else if (env->has_files != 0 && env->first == 0)
		ft_lst_bubble_sort(*node, ft_sort_by_lexycography_folder_end);
	else
		ft_lst_bubble_sort(*node, ft_sort_by_lexycography);
	if (g_options.r_maj)
		ft_sort_reverse(node);
}
