/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:27:16 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:57:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(char *str, char type)
{
	if (g_options.c && type)
	{
		if (type == 'd')
			ft_putstr_c(CYAN, str);
		else if (type == 'p')
			ft_putstr_c(YELLOW, str);
		else if (type == 'e')
			ft_putstr_c(RED, str);
		else
			ft_putstr(str);
	}
	else
		ft_putstr(str);
	if (type && type != 'e')
		g_options.lines++;
}

void	ft_printendl(char *str, char type)
{
	ft_print(str, type);
	ft_putchar('\n');
}

void	ft_print_c(char c, char type)
{
	if (g_options.c && type)
	{
		if (type == 'd')
			ft_putchar_c(CYAN, c);
		else if (type == 'p')
			ft_putchar_c(YELLOW, c);
		else if (type == 'e')
			ft_putchar_c(RED, c);
		else
			ft_putchar(c);
	}
	else if (c)
		ft_putchar(c);
}
