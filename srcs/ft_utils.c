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

char	*ft_errno(char *str)
{
	char	*err;

	err = ft_memalloc(sizeof(char)
		* (ft_strlen(str) + ft_strlen(strerror(errno))));
	ft_strcat(err, "ls: ");
	ft_strcat(err, ft_strdup(str));
	ft_strcat(err, ": ");
	ft_strcat(err, ft_strdup(strerror(errno)));
	return (err);
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
	if (lstat(new_elem->path, &new_elem->stat) == -1)
		ft_not_found_exit(str);
	else
		new_elem->type = ft_get_type_of(new_elem->stat);
	if (g_options.l && new_elem->type == 'l')
		ft_concat_linked_name(new_elem);
	return (new_elem);
}

int		reject_dot_folder(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (ft_strncmp(elem->name, ".", 1) == 0)
		return (0);
	return (1);
}

int		reject_dot(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (ft_strcmp(elem->name, ".") == 0 || ft_strcmp(elem->name, "..") == 0)
		return (0);
	return (1);
}
