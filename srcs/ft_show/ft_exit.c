/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:58:55 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 17:25:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_not_found_exit(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	if (errno != 0)
		ft_putstr(strerror(errno));
	else
		ft_putstr("No such file or directory");
	ft_putchar('\n');
}

void	ft_nill_not_found_exit()
{
	ft_putstr("ls: fts_open: No such file or directory\n");
	exit(0);
}


void	ft_illegal_option_exit(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	exit(0);
}

void	ft_memory_error()
{
	ft_putstr("error : memory cannot be allocated\n");
	exit(0);
}

void	ft_show_help()
{
	ft_putendl("-R  -- list subdirectories recursively");
	ft_putendl("-a  -- list entries starting with .");
	ft_putendl("-c  -- add colors to output");
	ft_putendl("-h  -- print information about command");
	ft_putendl("-l  -- long listing");
	ft_putendl("-r  -- reverse sort order");
	ft_putendl("-t  -- sort by modification time");
	exit(0);
}
