/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	concat_time(char *tmp_time, char *str_time)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		str_time[i] = tmp_time[i + 4];
		i++;
	}
}

static void	concat_date(char *tmp_time, char *str_time)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		str_time[i] = tmp_time[i + 4];
		i++;
	}
	while (i < 12)
	{
		str_time[i] = tmp_time[i + 12];
		i++;
	}
}

char		*ft_get_time(time_t timestamp)
{
	char	*tmp_time;
	char	*str_time;

	tmp_time = ctime(&timestamp);
	str_time = ft_strnew(12);
	if (((time(NULL) - timestamp) < 15552000)
		&& (timestamp < time(NULL) + 15552000))
		concat_time(tmp_time, str_time);
	else
		concat_date(tmp_time, str_time);
	return (str_time);
}

int			ft_get_max_time(t_elem *elem, t_elem *n_elem)
{
	if (elem->stat.st_mtime == n_elem->stat.st_mtime)
	{
		if (elem->stat.st_mtimespec.tv_nsec
			== n_elem->stat.st_mtimespec.tv_nsec
			&& ft_strcmp(elem->name, n_elem->name) > 0)
			return (1);
		else if (elem->stat.st_mtimespec.tv_nsec
			< n_elem->stat.st_mtimespec.tv_nsec)
			return (1);
		else
			return (0);
	}
	else if (elem->stat.st_mtime < n_elem->stat.st_mtime)
		return (1);
	else
		return (0);
}
