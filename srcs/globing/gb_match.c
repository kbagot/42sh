/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:10:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:43:28 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_sbmatch(char *s1, t_new *sb)
{
	int		ret;

	ret = -1;
	sb->i = 0;
	if (sb)
		while (sb->str && sb->str[sb->i])
		{
			if (sb->i == 0 && (sb->str[0] == '!' || sb->str[0] == '^')\
				&& sb->str[sb->i + 1] != '\0')
			{
				if (!(ret = sb_exclammatch(*s1, sb)))
					return (0);
				else
					return (1);
			}
			ret = check_shoot_more(*s1, sb);
			sb->i++;
			if (ret == 1)
				return (1);
		}
	return (0);
}

int		nmatch(char *s1, char *s2, t_new *sb)
{
	int		i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2, sb) + nmatch(s1, s2 + 1, sb));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1, sb));
	if (sb && *s2 == -42 && *s1 != '\0' && *s2 != '\0')
	{
		i = check_sbmatch(s1, sb);
		if (i == 0)
			return (0);
		else
			return (nmatch(s1 + 1, s2 + 1, sb->next));
	}
	if ((*s1 == *s2 || *s2 == '?') && *s1 != '\0' && *s2 != '\0')
		return (nmatch(s1 + 1, s2 + 1, sb));
	if ((*s1 == *s2 || *s2 == '?') && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

t_glob	*check_slash(t_glob *g, t_new *st_path, t_glob *save)
{
	t_new				*rec_path;
	t_new				*f_path;
	t_new				*izi;

	f_path = st_path;
	rec_path = NULL;
	izi = NULL;
	while (f_path != NULL)
	{
		if (g->slash != NULL)
		{
			rec_path = match_rep(g, f_path->str);
			izi = join_list(izi, rec_path);
		}
		else
			g = match_file(g, f_path);
		f_path = f_path->next;
	}
	free_resforever(st_path);
	if (izi != NULL)
		return (check_slash(g->slash, izi, save));
	else
		return (save);
}

t_glob	*add_everything(t_glob *g)
{
	t_glob		*gs;
	t_arg		*s;

	s = NULL;
	gs = g;
	while (gs)
	{
		s = gs->arg;
		while (s)
		{
			if (s->id == 0)
				gs = add_word(gs, s->str);
			else if (s->id == 1)
				gs = add_interro(gs);
			else if (s->id == 2)
				gs = add_sb(gs, s->str);
			else if (s->id == 3)
				gs = add_accolade(gs, s->str);
			s = s->next;
		}
		gs = gs->slash;
	}
	return (g);
}

t_glob	*do_we_match(t_glob *g)
{
	char	*tmp;
	t_new	*st_path;
	t_glob	*s;

	st_path = NULL;
	tmp = NULL;
	g = add_everything(g);
	s = g;
	if (!ft_strncmp(s->new->str, "~\0", 2))
	{
		tmp = ft_strdup(s->home);
		get_slashzero_home(g);
		s = s->slash;
	}
	else if (s->slashzero == 0)
		tmp = getcwd(NULL, 1024);
	else
		tmp = ft_strdup("/");
	st_path = add_path(st_path, tmp);
	ft_strdel(&tmp);
	g = check_slash(s, st_path, g);
	return (g);
}
