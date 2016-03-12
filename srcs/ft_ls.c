/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_opt(t_env *env)
{
	env->opt.l = 0;
	env->opt.R = 0;
	env->opt.a = 0;
	env->opt.r = 0;
	env->opt.t = 0;
}


int		main(int ac, char **av)
{
	ft_ls(ac, av);
	return (0);
}

void	ft_ls(int ac, char **av)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_memory_error();
	env->lst = NULL;
	ft_parser(env, ac, av);
	//ft_debug_t_opt(env->opt);
	//ft_elem_for_each(env, ft_debug_elems);
	ft_lstiter_plus(env->lst, env, ft_open_dir);
}
