/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:06:41 by nidzik            #+#    #+#             */
/*   Updated: 2018/01/05 11:22:14 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBING_H
# define GLOBING_H

# include "libft.h"

typedef struct	s_arg
{
	int				id;
	char			*str;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_new
{
	int				i;
	char			*str;
	struct s_new	*next;
}				t_new;

typedef struct	s_glob
{
	int				slashzero;
	struct s_arg	*arg;
	struct s_new	*new;
	struct s_new	*sb;
	struct s_new	*resforever;
	int				p[2];
	struct s_glob	*slash;
	char			*home;
}				t_glob;

typedef struct	s_fus
{
	int		i;
	char	**res;
	int		len_tab;
	int		len_tab2;

}				t_fus;

typedef struct	s_utils
{
	int		i;
	char	**res;
	char	*start;
	char	*tmp;
	int		j;
	char	*tmp2;
	char	*str;
	char	**res2;
}				t_utils;

typedef struct	s_zoom
{
	t_glob	*g;
	t_glob	*s;
	char	**env;
	char	*cmd;
	char	**split;
	t_new	*res;
	int		j;
	char	**end;
	int		i;
}				t_zoom;

/*
**gb_init
*/
t_glob			*init_glob();
t_glob			*add_glob_next(t_glob *g);
t_glob			*add_glob_slash(t_glob *g);
t_arg			*init_argument();
t_glob			*add_arg(t_glob *g, char *line, int a);
/*
**gb_init1
*/
t_new			*init_new();
t_new			*add_new(t_new *new);
t_glob			*add_sbplease(t_glob *g, char *str);
/*
**gb_research
*/
t_glob			*remake_arg(t_glob *g, char *line);
t_glob			*error_mush_arg(t_glob *s, char *line, int *j, int *i);
t_glob			*zoom_research(t_glob *g, char *line);
int				check_isglob(char *line);
char			**globing_research(char *cmd, char **env);
/*
**gb_possibility
*/
t_glob			*accolade(t_glob *g, char *line, int *i);
t_glob			*square_bracket(t_glob *g, char *line, int *i);
t_glob			*interogation(t_glob *g, char *line, int *i);
t_glob			*part_arg(t_glob *g, char *line, int *i);
t_glob			*slash_gestion(t_glob *g, char *line, int *i);
/*
**gb_checkposix
*/
int				check_name_pos(char *str);
int				check_is_posix(char *str, int *i);
int				sb_classmatch1(int c, t_new *sb);
int				sb_classmatch(int c, t_new *sb);
/*
**gb_addword
*/
char			*creat_bracket(int c);
t_glob			*add_accolade(t_glob *g, char *str);
t_glob			*add_interro(t_glob *g);
t_glob			*add_word(t_glob *g, char *str);
t_glob			*add_sb(t_glob *g, char *str);
/*
**gb_addword1
*/
t_new			*add_squarebreak(t_new *new);
/*
**gb_match
*/
int				check_sbmatch(char *s1, t_new *sb);
int				nmatch(char *s1, char *s2, t_new *sb);
t_glob			*check_slash(t_glob *g, t_new *st_path, t_glob *save);
t_glob			*add_everything(t_glob *g);
t_glob			*do_we_match(t_glob *g);
/*
**gb_match_pos
*/
int				sb_lessmatchno(int c, t_new *sb);
int				sb_exclammatch(int c, t_new *sb);
int				sb_lessmatch(int c, t_new *sb);
int				sb__match(int c, t_new *sb);
int				sb__match_no(int c, t_new *sb);
/*
**gb_matchrep
*/
char			*tri_join(int zero, char *path, char *str);
t_new			*match_rep(t_glob *g, char *path);
char			*found_path(int zero, char *path, char *dname);
t_glob			*match_file(t_glob *g, t_new *st_path);
/*
**gb_matchrep1
*/
t_new			*match_rep_end(t_glob *g, char *path, t_new *s,\
								t_new *new_path);
char			*found_path_zero(char *path, char *dname);
/*
**gb_recupchartab
*/
int				count_match(t_glob *g);
int				check_char42(char *s);
void			reverse_char42(char *s);
void			get_char42(char *s);
void			get_slashzero_home(t_glob *g);
/*
**gb_tools_match
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_isprint(int c);
/*
**gb_tools_match1
*/
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isword(int c);
int				ft_isblank(int c);
int				ft_isxdigit(int c);
/*
**gb_accolade
*/
int				check_pointpoint(char *line, int i);
int				check_comma(char *line, int i);
t_new			*add_joinaccolade(t_new *new, char *s1, char *s2);
t_new			*add_dupaccolade(t_new *new, char *str);
t_new			*make_pointpoint(t_new *new, char *str);
/*
**gb_accolade1
*/
t_new			*make_comma(t_new *new, char *str);
int				check_rebuild_path(char *str);
char			*rebuild_path(t_new *sb, char *str);
t_new			*rebuild_sb_struct(t_new *n_sb, t_new *s_sb);
t_new			*duplicate_sb(t_new *new, t_new *s);
/*
**gb_accolade2
*/
t_new			*make_pointpointdup(char *str);
t_new			*make_commadup(char **split);
/*
**gb_slash_gestion
*/
t_new			*join_list(t_new *izi, t_new *rec_path);
t_new			*add_path(t_new *st_path, char *path);
char			**list_to_tab_new(t_new *e);
/*
**gb_free
*/
void			free_split(char **split);
void			free_arg(t_arg *arg);
void			free_new(t_new *new);
void			free_resforever(t_new *resforever);
void			free_glob_slash(t_glob *g);
/*
**gb_acc
*/
char			**ft_split_acc(char *str, int check);
char			**ft_split_acc_tab(char **tab);
/*
**gb_acc2
*/
int				check_is_acc(char *str);
void			ft_print_tab(char **tab);
char			**ft_join_tab(char **tab, char *start);
int				check_res(char **tab);
void			free_two_tab(char **tab1, char **tab2);
/*
**gb_acc_handle_array
*/
char			**ft_fusion_array(char **tab1, char **tab2);
char			**ft_join_tab_end(char **tab, char *end);
void			ft_free_array(char **tab);
/*
**gb_get_env
*/
char			*gb_get_env(char **env);
t_new			*gb_home_path(t_new *res, t_glob *g);
/*
**gb_norme_research
*/
void			go_to_zoom_research(t_zoom *z);
void			go_to_acc(t_zoom *z);
void			init_z(t_zoom *z, char *cmd, char **env);
void			go_to_zoom(t_zoom *z);
/*
**gb_resultsb
*/
int				check_shoot_more(int c, t_new *sb);
int				check_shoot_exclam(int c, t_new *sb);
#endif
