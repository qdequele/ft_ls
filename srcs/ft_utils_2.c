/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:57:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_select_sort(t_env *env, t_list **node)
{
	if (g_options.t)
		ft_lst_bubble_sort(*node, ft_sort_by_modification_time);
	else
	{
		if (env->has_files != 0 && env->first == 0)
		{
			if (g_options.r)
			{
				ft_lst_bubble_sort(*node, ft_sort_by_lexycography_folder_end_r);
				return ;
			}
			else
				ft_lst_bubble_sort(*node, ft_sort_by_lexycography_folder_end);
		}
		else
			ft_lst_bubble_sort(*node, ft_sort_by_lexycography);
	}
	if (g_options.r)
		ft_sort_reverse(node);
}

void	ft_show_files(t_list *node)
{
	t_width	*w;

	w = ft_get_width_list(node);
	if (!g_options.l)
		ft_iter(node, ft_show_name);
	else if (w->total != 0)
	{
		ft_putstr("total ");
		ft_putnbr(w->total);
		ft_putchar('\n');
		ft_iter_plus(node, (void const *)w, ft_show_detailled_name);
	}
}

t_width	*ft_get_width_list(t_list *node)
{
	t_width	*w;

	w = (t_width *)ft_memalloc(sizeof(t_width));
	ft_init_width(w);
	ft_iter_plus(node, (void const *)w, ft_get_max_width);
	return (w);
}
