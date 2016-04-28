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
	i = 0;
	while (++i < ac && av[i] && av[i][0] == '-')
	{
		if (av[i][0] == '-' && av[i][1] == '-' && !av[i][2])
		{
			i++;
			break ;
		}
		if ((av[i][0] == '-' && !av[i][1]))
			break ;
		else if (av[i][0] == '-' && av[i][1] == '-' && av[i][2])
			ft_illegal_option_exit('-');
		else if (av[i][0] == '-' && av[i][1])
			ft_parse_options(env, av[i]);
	}
	if (!av[i])
		ft_parse_elems(env, ".");
	while (i < ac && av[i])
	{
		g_options.args++;
		ft_parse_elems(env, av[i++]);
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
	env = (t_env *)env;
	if (c == 'l')
		g_options.l = 1;
	else if (c == 'R')
		g_options.R = 1;
	else if (c == 'a')
		g_options.a = 1;
	else if (c == 'r')
		g_options.r = 1;
	else if (c == 't')
		g_options.t = 1;
	else if (c == 'c')
		g_options.c = 1;
	else if (c == 'h')
		g_options.h = 1;
	else if (c == '1')
	{
		g_options.one = 1;
		g_options.l = 0;
	}
	else
		ft_illegal_option_exit(c);
}

void	ft_parse_elems(t_env *env, char *str)
{
	t_elem	*new_elem;

	if (ft_strlen(str) == 0)
		ft_nill_not_found_exit();
	new_elem = ft_create_elem(str, "");
	if (new_elem->type != 'd')
		env->has_files++;
	ft_lstaddend(&(env->lst), ft_lstnew(new_elem, sizeof(t_elem)));
}
