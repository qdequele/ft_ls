/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:31:57 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:54:08 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_parser(t_env *env, int ac, char **av)
{
	int		i;

	ft_init_opt(env);
	i = 1;
	while (i < ac && av[i] && av[i][0] =='-')
	{
		if (av[i][0] =='-' && av[i][1] == '-' && !av[i][2] )
			break;
		else if (av[i][0] =='-' && av[i][1] == '-' && av[i][2] )
			ft_illegal_option_exit('-');
		else if (av[i][0] =='-' && av[i][1])
			ft_parse_options(env, av[i]);
		i++;
	}
	if (!av[i])
		ft_parse_elems(env, ".");
	while (i < ac && av[i])
	{
		env->opt.args++;
		ft_parse_elems(env, av[i]);
		i++;
	}
}

void	ft_parse_options(t_env *env, char *str)
{
	int		lenght;
	int		i;

	lenght = ft_strlen(str);
	i = 1;
	while (i < lenght && str[i])
	{
		ft_parse_option(env, str[i]);
		i++;
	}
}

void	ft_parse_option(t_env *env, char c)
{
	if (c == 'l')
		env->opt.l  = 1;
	else if (c == 'R')
		env->opt.R  = 1;
	else if (c == 'a')
		env->opt.a  = 1;
	else if (c == 'r')
		env->opt.r  = 1;
	else if (c == 't')
		env->opt.t  = 1;
	else if (c == 'n')
		env->opt.n  = 1;
	else if (c == 'c')
		env->opt.c  = 1;
	else if (c == 'i')
		env->opt.i  = 1;
	else if (c == 'h')
		env->opt.h  = 1;
	else if (c == 'F')
		env->opt.F  = 1;
	else if (c == 'L')
		env->opt.L  = 1;
	else if (c == 'S')
		env->opt.S  = 1;
	else if (c == 'T')
		env->opt.T  = 1;
	else if (c == 'g')
		env->opt.g  = 1;
	else if (c == 'm')
		env->opt.m  = 1;
	else
		ft_illegal_option_exit(c);
}

void	ft_parse_elems(t_env *env, char *str)
{
	t_elem	*new_elem;

	new_elem = ft_create_elem(str, "");
	if (new_elem->type != 'd')
		env->has_files++;
	ft_lstaddend(&(env->lst), ft_lstnew(new_elem, sizeof(t_elem)));
}