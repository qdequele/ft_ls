/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:03:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:33:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_float_right_text(int width, char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_strnew(width + 1);
	if (ft_strlen(str) >= (size_t)width)
		return (str);
	else
	{
		i = 0;
		j = 0;
		while (i < (width - (int)ft_strlen(str)))
			new_str[i++] = ' ';
		while (i < width)
			new_str[i++] = str[j++];
		new_str[i] = '\0';
	}
	return (new_str);
}

char	*ft_float_left_text(int width, char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_strnew(width + 1);
	if (ft_strlen(str) >= (size_t)width)
		return (str);
	else
	{
		i = 0;
		j = 0;
		while (i < (int)ft_strlen(str))
			new_str[i++] = str[j++];
		while (i < width)
			new_str[i++] = ' ';
		new_str[i] = '\0';
	}
	return (new_str);
}
