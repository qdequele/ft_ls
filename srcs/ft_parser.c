/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:31:57 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 12:03:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void    ft_parse_option(t_env *env, char *str)
{
    int lenght;
    int i;

    lenght = ft_strlen(str);
    i = 1;
    while (i < lenght && str[i])
    {
        if (str[i] == 'l')
            env->opt.l = 1;
        else if (str[i] == 'R')
            env->opt.R = 1;
        else if (str[i] == 'a')
            env->opt.a = 1;
        else if (str[i] == 'r')
            env->opt.r = 1;
        else if (str[i] == 't')
            env->opt.t = 1;
        else
            ft_illegal_option_exit(&str[i]);
        i++;
    }
}

void    ft_parse_files(t_env *env, char *str)
{
    t_file  *n_file;

    n_file = malloc(sizeof(t_file));
    n_file->path = malloc(sizeof(char) * (ft_strlen(str) + 1));
    n_file->path = str;
    if (stat(str, n_file->stat) != 0)
        n_file->err = ft_not_found_concat(str);
    else
        n_file->type = ft_get_type_of(n_file->stat);
    ft_lstaddend(&(env->files), ft_lstnew(n_file), sizeof(t_file));
}

void    ft_parser(t_env *env, int ac, char **av)
{
    int     i;

    ft_init_opt(env);
    i = 1;
    while (i < ac && av[i][0] =='-')
    {
        if (av[i][0] =='-' && av[i][1] == '-' && !av[i][2] )
            break;
        else if (av[i][0] =='-' && av[i][1] == '-' && av[i][2] )
            ft_illegal_option_exit("-");
        else if (av[i][0] =='-' && av[i][1])
            ft_parse_option(env, av[i]);
        i++;
    }
    while (i < ac && av[i])
    {
        if (av[i][0] =='-' && av[i][1] == '-' && !av[i][2] )
            break;
        else if (av[i][0] =='-' && av[i][1] == '-' && av[i][2] )
            ft_illegal_option_exit("-");
        else if (av[i][0] =='-' && av[i][1])
            ft_parse_option(env, av[i]);
        i++;
    }
}

char    *ft_not_found_concat(char *str)
{
    char    *err;
    err = malloc(sizeof(char) * (ft_strlen(str) + 32));
    ft_strcat(err, "ls:");
    ft_strcat(err, str);
    ft_strcat(err, ": No such file or directory\n");
    return (err);
}
