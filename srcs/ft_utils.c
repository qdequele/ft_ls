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
	{
		ft_putstr("type : b\n");
		return ('b');
	}
	if (S_ISCHR(stat.st_mode) == 1)
	{
		ft_putstr("type : c\n");
		return ('c');
	}
	if (S_ISDIR(stat.st_mode) == 1)
	{
		ft_putstr("type : d\n");
		return ('d');
	}
	if (S_ISFIFO(stat.st_mode) == 1)
	{
		ft_putstr("type : f\n");
		return ('f');
	}
	if (S_ISREG(stat.st_mode) == 1)
	{
		ft_putstr("type : -\n");
		return ('-');
	}
	if (S_ISLNK(stat.st_mode) == 1)
	{
		ft_putstr("type : l\n");
		return ('l');
	}
	else
	{
		ft_putstr("type : e\n");
		return ('e');
	}
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
