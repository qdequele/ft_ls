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
char	*ft_get_time(time_t timestamp)
{
	char	*tmp_time;
	char	*str_time;
	int		i;

	tmp_time = ctime(&timestamp);
	str_time = ft_strnew(12);
	i = 0;
	if ((time(NULL) - timestamp) < 15552000)
		while(i < 12)
		{
			str_time[i] = tmp_time[i + 4];
			i++;
		}
	else
	{
		while(i < 7)
		{
			str_time[i] = tmp_time[i + 4];
			i++;
		}
		while(i < 12)
		{
			str_time[i] = tmp_time[i + 12];
			i++;
		}
	}
	return (str_time);
}
char	*ft_get_right(mode_t st_mode)
{
	char 	*right;

	right = (char *)malloc(sizeof(char) * 10);
	right[0] = (st_mode & S_IRUSR)? 'r' : '-';
	right[1] = (st_mode & S_IWUSR)? 'w' : '-';
	right[2] = (st_mode & S_IXUSR)? 'x' : '-';
	right[2] = (st_mode & S_ISUID)? 'S' : right[2];
	right[2] = (st_mode & S_ISUID & S_IEXEC)? 's' : right[2];
	right[3] = (st_mode & S_IRGRP)? 'r' : '-';
	right[4] = (st_mode & S_IWGRP)? 'w' : '-';
	right[5] = (st_mode & S_IXGRP)? 'x' : '-';
	right[5] = (st_mode & S_ISGID)? 'S' : right[5];
	right[5] = (st_mode & S_ISGID & S_IXGRP)? 's' : right[5];
	right[6] = (st_mode & S_IROTH)? 'r' : '-';
	right[7] = (st_mode & S_IWOTH)? 'w' : '-';
	right[8] = (st_mode & S_IXOTH)? 'x' : '-';
	right[8] = (st_mode & S_ISVTX)? 't' : right[8];
	right[8] = (st_mode & S_ISVTX & S_IXOTH)? 'T' : right[8];
	right[9] = '\0';
	return (right);
}
void	ft_get_max_width(void const *st, t_list *node)
{
	t_elem	*elem;
	t_width	*w;

	elem = (t_elem *)node->content;
	w = (t_width *)st;
	if (elem->type == 'c' || elem->type == 'b')
		w->mm_format++;
	else
		w->size_format++;
	w->total += (int)elem->stat.st_blocks;
	ft_get_max_nlink(w, elem->stat);
	ft_get_max_uid(w, elem->stat);
	ft_get_max_gid(w, elem->stat);
	ft_get_max_major(w, elem->stat);
	ft_get_max_minor(w, elem->stat);
	ft_get_max_size(w, elem->stat);
	ft_get_max_sm(w, elem->stat);

}

void	ft_get_linked_name(t_elem *elem)
{
	char	*linkname;
	ssize_t	size;

	linkname = (char *)malloc(sizeof(char) * 256);
	size = readlink(elem->path, linkname, 256);
	linkname[size] = '\0';
	if (size > 0)
	{
		elem->name = ft_strfjoin(elem->name, ft_strdup(" -> "));
		elem->name = ft_strfjoin(elem->name, linkname);
	}
}