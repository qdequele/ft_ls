/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_opt(t_env *env)
{
	g_options.l = 0;
	g_options.R = 0;
	g_options.a = 0;
	g_options.r = 0;
	g_options.t = 0;
	g_options.c = 0;
	g_options.h = 0;
	g_options.one = 0;
	g_options.args = 0;
	env->first = 0;
	env->has_files = 0;
	g_options.err = 0;
	g_options.lines = 0;
}

void	ft_init_width(t_width *w)
{
	w->nlink = 0;
	w->uid = 0;
	w->gid = 0;
	w->minor = 0;
	w->major = 0;
	w->size = 0;
	w->sm = 0;
	w->total = 0;
	w->size_format = 0;
	w->mm_format = 0;
}