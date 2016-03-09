/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:33:38 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/02 18:19:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_env(t_env *env)
{
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_memory_error();
	env->elems = NULL;
}

void	ft_init_opt(t_env *env)
{
	env->opt.l = 0;
	env->opt.R = 0;
	env->opt.a = 0;
	env->opt.r = 0;
	env->opt.t = 0;
}
