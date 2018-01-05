/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_addword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:10:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:10:15 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

char	*creat_bracket(int c)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

t_glob	*add_accolade(t_glob *g, char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 4)
	{
		if (ft_isalnum(str[i]) && str[i + 1] == '.' &&\
			str[i + 2] == '.' && ft_isalnum(str[i + 3]))
			g->new = make_pointpoint(g->new, str);
		else
			g->new = make_comma(g->new, str);
	}
	else
		g->new = make_comma(g->new, str);
	return (g);
}

t_glob	*add_interro(t_glob *g)
{
	t_new	*s;
	char	*tmp;

	tmp = NULL;
	s = g->new;
	if (s != NULL)
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, "?");
			ft_strdel(&tmp);
			s = s->next;
		}
	else
	{
		g->new = add_new(g->new);
		g->new->str = ft_strdup("?");
	}
	return (g);
}

t_glob	*add_word(t_glob *g, char *str)
{
	t_new		*s;
	char		*tmp;

	s = g->new;
	tmp = NULL;
	if (s != NULL)
	{
		while (s != NULL)
		{
			tmp = ft_strdup(s->str);
			ft_strdel(&(s->str));
			s->str = ft_strjoin(tmp, str);
			ft_strdel(&tmp);
			s = s->next;
		}
	}
	else
	{
		g->new = add_new(g->new);
		g->new->str = ft_strdup(str);
	}
	return (g);
}

t_glob	*add_sb(t_glob *g, char *str)
{
	t_new	*sb;
	char	*tmp;
	char	*w;

	sb = NULL;
	tmp = NULL;
	w = NULL;
	if (g && g->new)
	{
		g = add_sbplease(g, str);
		g->new = add_squarebreak(g->new);
	}
	else
	{
		g->new = init_new();
		g->new->str = creat_bracket(-42);
		g = add_sbplease(g, str);
	}
	return (g);
}
