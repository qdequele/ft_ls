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
	if (S_ISCHR(stat.st_mode) == 1)
		return ('c');
	else
		return ('e');
}

char	*ft_not_found_concat(char *str)
{
	char	*err;
	err = malloc(sizeof(char) * (ft_strlen(str) + 32));
	ft_strcat(err, "ls: ");
	ft_strcat(err, str);
	ft_strcat(err, ": No such file or directory");
	return (err);
}

t_elem	*ft_create_elem(char *str, char *prev_path)
{
	t_elem	*new_elem;

	if (!(new_elem = malloc(sizeof(t_elem))))
		ft_memory_error();
	if (!(new_elem->path = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(prev_path) + 1))))
		ft_memory_error();
	if (strcmp(prev_path, ".") == 0)
		new_elem->path = str;
	else
	{
		if (ft_strlen(prev_path) > 0)
			prev_path = ft_strjoin(prev_path, "/");
		new_elem->path = ft_strjoin(prev_path, str);
	}
	new_elem->name = str;
	if (lstat(new_elem->path, &new_elem->stat) == -1)
	{
		new_elem->err = ft_not_found_concat(str);
	}
	else
	{
		new_elem->type = ft_get_type_of(new_elem->stat);
	}
	return (new_elem);
}

void	ft_free_elem(void *content, size_t size)
{
	t_elem	*elem;

	size = 0;
	elem = (t_elem*)content;
	if (elem->name)
		free(elem->name);
	if (elem->path)
		free(elem->path);
	if (elem->err)
		free(elem->err);
	free(elem);
}

int		reject_dot_folder(t_list *node)
{
	t_elem	*elem;

	elem = node->content;
	if (strncmp(elem->name, ".", 1) == 0)
		return (0);
	return (1);
}