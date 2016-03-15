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

char	*ft_get_name(uid_t uid)
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
	while(i < 12)
	{
		str_time[i] = tmp_time[i + 4];
		i++;
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
	right[3] = (st_mode & S_IRGRP)? 'r' : '-';
	right[4] = (st_mode & S_IWGRP)? 'w' : '-';
	right[5] = (st_mode & S_IXGRP)? 'x' : '-';
	right[6] = (st_mode & S_IROTH)? 'r' : '-';
	right[7] = (st_mode & S_IWOTH)? 'w' : '-';
	right[8] = (st_mode & S_IXOTH)? 'x' : '-';
	right[9] = '\0';
	return (right);
}