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
	if (S_ISCHR(stat.st_mode) == 1)
		return ('c');
	if (S_ISDIR(stat.st_mode) == 1)
		return ('d');
	if (S_ISFIFO(stat.st_mode) == 1)
		return ('f');
	if (S_ISREG(stat.st_mode) == 1)
		return ('-');
	if (S_ISLNK(stat.st_mode) == 1)
		return ('l');
	else
		return ('e');
}

char	*ft_not_found_concat(char *str)
{
	char	*err;
	err = malloc(sizeof(char) * (ft_strlen(str) + 32));
	ft_strcat(err, "ls:");
	ft_strcat(err, str);
	ft_strcat(err, ": No such file or directory\n");
	return (err);
}

t_elem	*ft_create_elem(char *str, char *prev_path)
{
	t_elem	*new_elem;

	if (!(new_elem = malloc(sizeof(t_elem))))
		ft_memory_error();
	if (!(new_elem->path = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(prev_path) + 1))))
		ft_memory_error();
	if (ft_strlen(prev_path) > 0)
		prev_path = ft_strjoin(prev_path, "/");
	new_elem->path = ft_strjoin(prev_path, str);
	new_elem->name = str;
	new_elem->next = NULL;
	if (lstat(str, &new_elem->stat) == -1)
	{
		new_elem->err = ft_not_found_concat(str);
	}
	else
	{
		new_elem->type = ft_get_type_of(new_elem->stat);
	}
	return (new_elem);
}

int		reject_dot_folder(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (strcmp(elem->name, ".") == 0 || strcmp(elem->name, "..") == 0)
		return (0);
	return (1);
}