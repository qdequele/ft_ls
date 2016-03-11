/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_open_dir(t_elem *elem)
{
	struct dirent *pDirent;
	DIR *pDir;

	ft_debug_elems(elem);
	pDir = NULL;
	if (elem->type == 'd')
	{
		ft_putstr("\n./");
		ft_putstr(elem->path);
		ft_putstr(":\n");
		pDir = opendir (elem->path);
		if (pDir == NULL) {
			ft_not_found_exit(elem->path);
		}
		while ((pDirent = readdir(pDir)) != NULL) {
			printf ("%s\n", pDirent->d_name);
		}
		closedir (pDir);
	}
	else
	{
		ft_putstr("\n");
		ft_putstr(elem->path);
		ft_putstr("\n");
	}
}