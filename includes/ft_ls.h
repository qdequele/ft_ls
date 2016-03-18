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
# include <pwd.h>
# include <grp.h>
# include <time.h>
#include <stdio.h>


typedef struct		s_elem
{
	struct stat		stat;
	char			*name;
	char			*path;
	char			*err;
	char			type;
}					t_elem;

typedef struct		s_width
{
	size_t			nlink;
	size_t			uid;
	size_t			gid;
	size_t			major;
	size_t			minor;
	size_t			size;
	size_t			sm;
	size_t			total;
	int				size_format;
	int				mm_format;
}					t_width;

typedef struct		s_opt
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	int				c;
	int				h;
	int				args;
}					t_opt;

t_opt				g_options;

typedef struct		s_env
{
	t_list			*lst;
	int				first;
	int				has_files;
}					t_env;

/*
** ft_align.c
*/
char				*ft_float_right_text(int width, char *str);
char				*ft_float_left_text(int width, char *str);
/*
** ft_compute.c
*/
void				ft_compute(const void *env, t_list *lst);
void				ft_compute_dir(const void *ev, t_list *node);
void				ft_select_sort(t_env *env, t_list **node);
void				ft_show_files(t_list *node);
/*
** ft_debug.c
*/
void				ft_debug_t_opt(t_opt opt);
void				ft_debug_elems(t_list *node);
/*
** ft_exit.c
*/
void				ft_not_found_exit(char *str);
void				ft_nill_not_found_exit();
void				ft_illegal_option_exit(char c);
void				ft_memory_error();
void				ft_show_help();
/*
** ft_get_info.c
*/
char				*ft_get_user(uid_t uid);
char				*ft_get_group(gid_t gid);
char				*ft_get_time(time_t timestamp);
char				*ft_get_right(mode_t st_mode);
void				ft_get_max_width(void const *st, t_list *node);
void				ft_get_linked_name(t_elem *elem);
/*
** ft_init.c
*/
void				ft_init_opt(t_env *env);
void				ft_init_width(t_width *w);
/*
** ft_iter.c
*/
void				ft_iter(t_list *node, void (*f)(t_list *elem));
void				ft_iter_plus(t_list *node, void const *param, void (*f)(void const *info, t_list *elem));
/*
** ft_ls.c
*/
void				ft_ls(int ac, char **av);
/*
** ft_parser.c
*/
void				ft_parser(t_env *env, int ac, char **av);
void				ft_parse_options(t_env *env, char *str);
void				ft_parse_option(t_env *env, char c);
void				ft_parse_elems(t_env *env, char *str);
/*
** ft_print.c
*/
void				ft_print(char *str, char type);
void				ft_printendl(char *str, char type);
void				ft_print_c(char c, char type);
/*
** ft_show.c
*/
void				ft_show_name(t_list *node);
void				ft_show_path(t_env *env, t_elem *elem);
/*
** ft_show_long.c
*/
void				ft_show_detailled_name(void const *w, t_list *node);
void				ft_show_uid_gid(t_width *w, t_elem	*elem);
void				ft_show_size(t_width *w, t_elem	*elem);
void				ft_show_date(t_elem	*elem);
/*
** ft_sort.c
*/
int					ft_sort_by_lexycography(t_list *node);
int					ft_sort_by_lexycography_folder_end(t_list *node);
int					ft_sort_by_lexycography_folder_end_r(t_list *node);
int					ft_sort_by_modification_time(t_list *node);
int					ft_sort_reverse(t_list **node);
/*
** ft_utils.c
*/
char				ft_get_type_of(struct stat stat);
char				*ft_not_found_concat(char *str);
t_elem				*ft_create_elem(char *str, char *prev_path);
void				ft_free_elem(void *content, size_t size);
int					reject_dot_folder(t_list *node);
#endif
