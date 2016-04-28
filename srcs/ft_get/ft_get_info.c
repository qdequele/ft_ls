/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_user(uid_t uid)
{
	struct passwd *result;

	result = getpwuid(uid);
	return (result->pw_name);
}

char	*ft_get_group(gid_t gid)
{
	struct group *result;

	result = getgrgid(gid);
	return (result->gr_name);
}

char	*ft_get_right(mode_t st_mode)
{
	char	*right;

	right = ft_memalloc(sizeof(char) * 10);
	right[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	right[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	right[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	right[2] = (st_mode & S_ISUID) ? 'S' : right[2];
	right[2] = ((st_mode & S_ISUID) && (st_mode & S_IXUSR)) ? 's' : right[2];
	right[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	right[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	right[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	right[5] = (st_mode & S_ISGID) ? 'S' : right[5];
	right[5] = ((st_mode & S_ISGID) && (st_mode & S_IXGRP)) ? 's' : right[5];
	right[6] = (st_mode & S_IROTH) ? 'r' : '-';
	right[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	right[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	right[8] = (st_mode & S_ISVTX) ? 'T' : right[8];
	right[8] = ((st_mode & S_ISVTX) && (st_mode & S_IXOTH)) ? 't' : right[8];
	right[9] = '\0';
	return (right);
}

char	*ft_get_linked_name(t_elem *elem)
{
	char	*linkname;
	ssize_t	size;

	linkname = ft_memalloc(sizeof(char) * 256);
	size = readlink(elem->path, linkname, 256);
	linkname[size] = '\0';
	if (size > 0)
		return (linkname);
	else
		return (NULL);
}

void	ft_concat_linked_name(t_elem *elem)
{
	char	*linkname;

	linkname = ft_get_linked_name(elem);
	if (linkname)
	{
		elem->name = ft_strfjoin(elem->name, ft_strdup(" -> "));
		elem->name = ft_strfjoin(elem->name, linkname);
	}
}
