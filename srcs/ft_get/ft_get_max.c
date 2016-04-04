/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	ft_get_max_nlink(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen((int)stat.st_nlink) > w->nlink)
		w->nlink = ft_nbrlen((int)stat.st_nlink);
}

void	ft_get_max_uid(t_width *w, struct stat stat)
{
	if (ft_strlen(ft_get_user((int)stat.st_uid)) > w->uid)
		w->uid = ft_strlen(ft_get_user((int)stat.st_uid));
}

void	ft_get_max_gid(t_width *w, struct stat stat)
{
	if (ft_strlen(ft_get_group((int)stat.st_gid)) > w->gid)
		w->gid = ft_strlen(ft_get_group((int)stat.st_gid));
}

void	ft_get_max_major(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen(major((int)stat.st_rdev)) > w->major)
		w->major = ft_nbrlen(major((int)stat.st_rdev));
}

void	ft_get_max_minor(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen(minor((int)stat.st_rdev)) > w->minor)
		w->minor = ft_nbrlen(minor((int)stat.st_rdev));
}

void	ft_get_max_size(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen((int)stat.st_size) > w->size)
		w->size = ft_nbrlen((int)stat.st_size);
}

void	ft_get_max_sm(t_width *w, struct stat stat)
{
	if ((size_t)ft_nbrlen((int)stat.st_size) > w->sm)
		w->sm = ft_nbrlen((int)stat.st_size);
	if ((size_t)ft_nbrlen(major((int)stat.st_rdev)) +
		(size_t)ft_nbrlen(major((int)stat.st_rdev)) + 2 > w->sm)
		w->sm = (size_t)ft_nbrlen(major((int)stat.st_rdev)) +
				(size_t)ft_nbrlen(major((int)stat.st_rdev)) + 2;
}