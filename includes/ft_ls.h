/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
#include <stdio.h>


typedef struct		s_elem
{
	struct stat		stat;
	char			*name;
	char			*path;
	char			*err;
	char			type;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_opt
{
	int				l;//List with all atributes--
	int				R;//Recursive -- OK
	int				a;//include hidden file (.*) -- OK
	int				r;//reverse sorting -- OK
	int				t;//sort by last modification --
	int				args;// if ls have params -- OK
}					t_opt;

typedef struct		s_env
{
	t_opt			opt;
	t_list			*lst;
}					t_env;

//ft_dir.c
void				ft_compute(const void *env, t_list *lst);
void				ft_compute_dir(const void *ev, t_list *node);
void				ft_select_sort(t_env *env, t_list *node);
void				ft_show_path(t_env *env, t_elem *elem);
void				ft_show_files(t_env *env, t_list *node);
//ft_exit.c
void				ft_not_found_exit(char *str);
void				ft_illegal_option_exit(char *str);
void				ft_memory_error();
//ft_ls.c
void				ft_init_opt(t_env *env);
void				ft_ls(int ac, char **av);
//ft_parser.c
void				ft_parse_option(t_env *env, char *str);
void				ft_parse_elems(t_env *env, char *str);
void				ft_parser(t_env *env, int ac, char **av);
//ft_show.c
void				ft_debug_t_opt(t_opt opt);
void				ft_debug_elems(t_list *node);
void				ft_show_name(t_list *node);
//ft_sort.c
int					ft_sort_by_modification_time(t_list *node);
int					ft_sort_reverse(t_list *node);
int					ft_sort_by_lexycography(t_list *node);
//ft_utils.c
char				ft_get_type_of(struct stat stat);
char				*ft_not_found_concat(char *str);
t_elem				*ft_create_elem(char *str, char *prev_path);
int					reject_dot_folder(t_list *node);
#endif
